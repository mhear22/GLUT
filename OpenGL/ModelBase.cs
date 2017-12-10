using System;
using System.Collections.Generic;
using System.Text;
using OpenTK.Graphics.OpenGL4;

namespace Weave
{
	public abstract class ModelBase
	{
		private DrawTool tool;
		public ModelBase(DrawTool tool)
		{
			this.tool = tool;
		}

		protected int VAO;
		protected int VBO;
		
		public abstract void Draw();
	}
}
