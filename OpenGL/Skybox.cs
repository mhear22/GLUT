using System;
using System.Collections.Generic;
using System.Text;
using OpenTK.Graphics.OpenGL4;

namespace Weave
{
	public class Skybox : ModelBase
	{
		public Skybox(DrawTool tool)
			: base(tool)
		{
			this.Load();
		}
 

		private int _start;
		private int _end;

		public void Load()
		{
			GL.GenVertexArrays(1, out this.VAO);
			GL.BindVertexArray(this.VAO);

			GL.GenBuffers(1, out this.VBO);
			GL.BindBuffer(BufferTarget.ArrayBuffer, this.VBO);


			float[] vertex =
			{
				-1, 1, 1,
				-1,-1, 1,
				1,-1, 1,

				-1, 1, 1,
				1,-1, 1,
				1, 1, 1,

				-1, 1,-1,
				-1,-1,-1,
				1,-1,-1,

				-1, 1,-1,
				1,-1,-1,
				1, 1,-1,
			};

			_start = 0;
			_end = vertex.Length * sizeof(float);
			
			GL.BufferData(BufferTarget.ArrayBuffer, sizeof(float), vertex, BufferUsageHint.StaticDraw);
			GL.BindBuffer(BufferTarget.ArrayBuffer, 0);
			GL.BindVertexArray(0);
		}

		public override void Draw()
		{
			GL.BindVertexArray(this.VAO);
			GL.DrawArrays(PrimitiveType.Triangles, _start, _end);
			GL.BindVertexArray(0);
		}
	}
}
