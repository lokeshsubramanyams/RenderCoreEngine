// main.js


const wasmJs = 'RenderCoreEngine.js';
document.addEventListener('DOMContentLoaded', (event) => {
  console.log("DOM fully loaded and parsed");

  const canvas = document.createElement('canvas');
  canvas.width = 640;
  canvas.height = 480;
  canvas.id = 'canvas';
  canvas.style.border = '4px solid black';
  document.body.appendChild(canvas);

  window.Module = {
    canvas: canvas, // Explicitly set the canvas for the Emscripten module
    onRuntimeInitialized: function () {
      console.log("WebAssembly module initialized");
      try {
        Module._igniteEngine("");
      } catch (e) {
        console.error('Error initializing the engine:', e);
      }
    }
  };

  // Load the WebAssembly script after configuring the Module
  const wasmScript = document.createElement('script');
  wasmScript.src = wasmJs;
  document.body.appendChild(wasmScript);
  wasmScript.onload = () => {
    console.log("WASM JS loaded");
  };
});