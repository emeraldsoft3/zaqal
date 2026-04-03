import mill._
import mill.scalalib._

object zaqal extends ScalaModule {
  override def scalaVersion = "2.13.15"

  // Standard ivyDeps for Mill 0.11.x
  override def ivyDeps = T {
    Agg(
      ivy"org.chipsalliance::chisel:6.6.0",
      ivy"org.chipsalliance::chiseltest:6.0.0",
      ivy"org.chipsalliance::cde:0.2.0"
    )
  }

  // Compiler plugin for macro annotations and Chisel
  override def scalacPluginIvyDeps = T {
    Agg(
      ivy"org.chipsalliance:::chisel-plugin:6.6.0"
    )
  }

  override def scalacOptions = T {
    Seq("-Ymacro-annotations")
  }

  // Explicitly defining sources to avoid any SbtModule layout confusion
  override def sources = T.sources(
    millSourcePath / "src" / "main" / "scala"
  )

  override def millSourcePath = os.pwd
}
