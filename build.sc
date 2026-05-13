import mill._
import scalalib._

// Import the local CDE submodule build definition with a unique name
import $file.dependencies.cde.{build => cdeBuild}

// Define a common template for all Zaqal modules
trait ZaqalModule extends ScalaModule {
  def scalaVersion = "2.13.15"

  override def ivyDeps = T {
    super.ivyDeps() ++ Agg(
      ivy"org.chipsalliance::chisel:6.6.0"
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
}

// 1. Common Parameters & Bundles (Depends on CDE)
object common extends ZaqalModule {
  override def millSourcePath = os.pwd / "common"
  override def moduleDeps = Seq(cdeBuild.cde)
}

// 2. Generic Utilities (SkidBuffer, etc.)
object utility extends ZaqalModule {
  override def millSourcePath = os.pwd / "utility"
  override def moduleDeps = Seq(common)
}

// 3. Frontend (BPU, FTQ, IFU)
object frontend extends ZaqalModule {
  override def millSourcePath = os.pwd / "frontend"
  override def moduleDeps = Seq(common, utility)
}

// 4. Backend (ALU, RegFile, Decode)
object backend extends ZaqalModule {
  override def millSourcePath = os.pwd / "backend"
  override def moduleDeps = Seq(common, utility)
}

// 5. Main Zaqal Core (Top level, Simulation, Elaborate)
object zaqal extends ZaqalModule {
  override def millSourcePath = os.pwd / "zaqal"
  override def moduleDeps = Seq(frontend, backend)

  // Simulation and Test dependencies
  override def ivyDeps = T {
    super.ivyDeps() ++ Agg(
      ivy"edu.berkeley.cs::chiseltest:6.0.0"
    )
  }

  object test extends ScalaTests with TestModule.ScalaTest {
    override def ivyDeps = T {
      super.ivyDeps() ++ Agg(
        ivy"org.scalatest::scalatest:3.2.19"
      )
    }
  }
}
