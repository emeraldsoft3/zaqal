package org.chipsalliance.cde.config

abstract class Field[T]

abstract class View {
  def find[T](f: Field[T]): Option[T]
  def apply[T](f: Field[T]): T = find(f).getOrElse(throw new Exception(s"Field $f not found"))
  def lift[T](f: Field[T]): Option[T] = find(f)
}

abstract class Parameters extends View {
  def chain(next: Parameters): Parameters = new ChainParameters(this, next)
  def alter(f: (Field[_], Option[Any], View) => Option[Any]): Parameters =
    new AlterParameters(this, f)
  def alterPartial(f: PartialFunction[Field[_], Any]): Parameters =
    alter((field, _, _) => f.lift(field))
  def alterMap(m: Map[Field[_], Any]): Parameters =
    alter((field, _, _) => m.get(field))
}

object Parameters {
  def empty: Parameters = new EmptyParameters
}

class EmptyParameters extends Parameters {
  def find[T](f: Field[T]): Option[T] = None
}

class ChainParameters(inner: Parameters, outer: Parameters) extends Parameters {
  def find[T](f: Field[T]): Option[T] = inner.find(f).orElse(outer.find(f))
}

class AlterParameters(
  inner: Parameters,
  alteration: (Field[_], Option[Any], View) => Option[Any]
) extends Parameters {
  def find[T](f: Field[T]): Option[T] =
    alteration(f, inner.find(f), this).asInstanceOf[Option[T]]
}


class Config(val f: (Field[_], Option[Any], View) => Option[Any]) extends Parameters {
  def find[T](f: Field[T]): Option[T] = this.f(f, None, this).asInstanceOf[Option[T]]
  override def alter(g: (Field[_], Option[Any], View) => Option[Any]): Config =
    new Config((f, v, p) => g(f, this.f(f, v, p), p))
  def ++(other: Config): Config =
    new Config((f, v, p) => other.f(f, this.f(f, v, p), p))
    
  def toInstance: Parameters = this
}

object Config {
  def empty: Config = new Config((_, _, _) => None)
  
  // Helper for applying PartialFunctions easily
  def apply(f: (View, View, View) => PartialFunction[Field[_], Any]): Config = {
    new Config((field, _, p) => {
      val pf = f(p, p, p)
      if (pf.isDefinedAt(field)) Some(pf(field)) else None
    })
  }
}
