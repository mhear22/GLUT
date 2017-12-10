using System;
using System.Collections.Generic;
using System.Text;
using OpenTK.Graphics.OpenGL4;
using System.IO;

namespace Weave.Shaders
{
	public class Shader
	{
		private int _object;

		public Shader(ShaderType shaderType, string ShaderPath)
		{
			_object = GL.CreateShader(shaderType);
			if (_object == 0)
			{
				throw new Exception("Could not into shader");
			}

			var file = File.ReadAllText(ShaderPath);

			GL.ShaderSource(_object, file);

			GL.CompileShader(_object);
		}
	}
}
