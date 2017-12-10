using System;
using System.Collections.Generic;
using System.Text;
using OpenTK.Graphics.OpenGL4;

namespace Weave
{
	public class DrawTool
	{
		private int _program;

		public DrawTool(int program)
		{
			this._program = program;
		}

		public int GetAttribute(string glchars)
		{
			var atrib = GL.GetAttribLocation(this._program, glchars);

			if(atrib == -1)
			{
				throw new Exception("");
			}
			return atrib;
		}
	}
}
