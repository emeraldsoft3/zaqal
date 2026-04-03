import mill._
import scalalib._

object zaqal extends ScalaModule {
  override def scalaVersion = "2.13.15"

  override def ivyDeps = T {
    super.ivyDeps() ++ Agg(
      ivy"org.chipsalliance::chisel:6.6.0",
      ivy"edu.berkeley.cs::chiseltest:6.0.0"
    )
  }

  override def scalacPluginIvyDeps = T {
    super.scalacPluginIvyDeps() ++ Agg(
      ivy"org.chipsalliance:::chisel-plugin:6.6.0"
    )
  }

  override def scalacOptions = T {
    super.scalacOptions() ++ Agg("-Ymacro-annotations")
  }

  override def sources = T.sources(
    millSourcePath / "src" / "main" / "scala"
  )

  override def millSourcePath = os.pwd
}
