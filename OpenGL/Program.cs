using OpenTK;
using OpenTK.Graphics;
using System;
using OpenTK.Graphics.OpenGL4;
using OpenTK.Input;
using System.IO;
using Newtonsoft.Json;

namespace Weave
{
	public class Program
	{
		public static void Main()
		{
			ConfigModel configModel = null;

			try {
				var configDir = Directory.GetCurrentDirectory() + "\\config.json";
				var file = File.ReadAllText(configDir);
				configModel = JsonConvert.DeserializeObject<ConfigModel>(file);
			}
			catch (Exception ex) { }

			if(configModel!=null) {
				using (var game = new Game(configModel))
				{
					game.Run(144.0);
				}
			}
			else {
				using(var game = new Game())
				{
					game.Run(144.0);
				}
			}
		}
	}

	public class Game : GameWindow
	{
		public Game(ConfigModel model)
			: base(
				model.Width??640,
				model.Height??480,
				GraphicsMode.Default,
				"Weave",
				GameWindowFlags.FixedWindow,
				DisplayDevice.GetDisplay((DisplayIndex)(model.MonitorIndex??-1)),
				4,1,
				GraphicsContextFlags.Default
			)
		{
			
		}
		
		public Game()
			: base(
				1920,1080,
				GraphicsMode.Default,
				"Weave",
				GameWindowFlags.FixedWindow,
				DisplayDevice.GetDisplay(DisplayIndex.Default),
				4,1,
				GraphicsContextFlags.Default)
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

			if(e.Key == Key.F4 && e.Alt)
				Exit();
		}

		protected override void OnRenderFrame(FrameEventArgs e)
		{
			base.OnRenderFrame(e);

			GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);
			

			SwapBuffers();
		}
	}
}