// main.js


const wasmJs = 'RenderCoreEngine.js';
document.addEventListener('DOMContentLoaded', (event) => {
  console.log("DOM fully loaded and parsed");

  const canvas = document.createElement('canvas');
  canvas.width = 640; // Width in pixels
  canvas.height = 480; // Height in pixels
  canvas.id = 'canvas';
  canvas.style.border = '4px solid black';
  document.body.appendChild(canvas);

  const webglConfig = {
    stencil: true,
    depth: true,
    antialias: true,
    alpha: true,
    majorVersion: 2,
    minorVersion: 0
  };



  const wasmScript = document.createElement('script');
  wasmScript.src = wasmJs;
  document.body.appendChild(wasmScript);
  wasmScript.onload = () => {
    console.log("wasm js loaded");
    Module.onRuntimeInitialized = () => {

      console.log("web assembly module initialized");
      console.log(canvas);
      try {
        // const gl = canvas.getContext("webgl2", webglConfig);
        Module._igniteEngine(canvas); // Assuming _igniteEngine is expecting the canvas and WebGL context
      } catch (e) {
        console.error('Error initializing the engine:', e);
      }
    };
  };

});