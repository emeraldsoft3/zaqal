import mill._
import mill.scalalib._

object `package` extends SbtModule {
  override def scalaVersion = "2.13.15"

  // Chisel Library
  override def mvnDeps = Task {
    Seq(
      mvn"org.chipsalliance::chisel:6.6.0",
      mvn"edu.berkeley.cs::chiseltest:6.0.0" // Add this for simulation
    )
  }

  // UPDATED: In Mill 1.0.6, the method is scalacPluginMvnDeps
  override def scalacPluginMvnDeps = Task {
    Seq(
      mvn"org.chipsalliance:::chisel-plugin:6.6.0"
    )
  }

  override def scalacOptions = Task {
    Seq(
      "-language:reflectiveCalls",
      "-deprecation",
      "-feature"
    )
  }
}