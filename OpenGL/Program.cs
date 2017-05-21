using OpenTK;
using OpenTK.Graphics;
using System;
using OpenTK.Graphics.OpenGL4;
using OpenTK.Input;

namespace ConsoleApp1
{
	public class Program
	{
		static void Main(string[] args)
		{
			using(var game = new Game())
			{
				game.Run(144.0);
			}
		}
	}

	public class Game : GameWindow
	{
		public Game()
			: base(1920, 1080, GraphicsMode.Default, "", GameWindowFlags.FixedWindow)
		{
			
		}

		protected override void OnLoad(EventArgs e)
		{
			base.OnLoad(e);
			GL.ClearColor(0, 0, 0, 0);
			GL.Enable(EnableCap.DepthTest);
		}

		protected override void OnKeyUp(KeyboardKeyEventArgs e)
		{
			base.OnKeyUp(e);

			if(e.Key == Key.Escape)
			{
				Exit();
			}
		}

		protected override void OnRenderFrame(FrameEventArgs e)
		{
			base.OnRenderFrame(e);

			GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);
			

			SwapBuffers();
		}
	}
}