function GROWABLE_HEAP_I8() {
  if (wasmMemory.buffer != HEAP8.buffer) {
    updateMemoryViews()
  }
  return HEAP8
}

function GROWABLE_HEAP_U8() {
  if (wasmMemory.buffer != HEAP8.buffer) {
    updateMemoryViews()
  }
  return HEAPU8
}

function GROWABLE_HEAP_I16() {
  if (wasmMemory.buffer != HEAP8.buffer) {
    updateMemoryViews()
  }
  return HEAP16
}

function GROWABLE_HEAP_U16() {
  if (wasmMemory.buffer != HEAP8.buffer) {
    updateMemoryViews()
  }
  return HEAPU16
}

function GROWABLE_HEAP_I32() {
  if (wasmMemory.buffer != HEAP8.buffer) {
    updateMemoryViews()
  }
  return HEAP32
}

function GROWABLE_HEAP_U32() {
  if (wasmMemory.buffer != HEAP8.buffer) {
    updateMemoryViews()
  }
  return HEAPU32
}

function GROWABLE_HEAP_F32() {
  if (wasmMemory.buffer != HEAP8.buffer) {
    updateMemoryViews()
  }
  return HEAPF32
}

function GROWABLE_HEAP_F64() {
  if (wasmMemory.buffer != HEAP8.buffer) {
    updateMemoryViews()
  }
  return HEAPF64
}
var Module = typeof Module != "undefined" ? Module : {};
var moduleOverrides = Object.assign({}, Module);
var arguments_ = [];
var thisProgram = "./this.program";
var quit_ = (status, toThrow) => {
  throw toThrow
};
var ENVIRONMENT_IS_WEB = typeof window == "object";
var ENVIRONMENT_IS_WORKER = typeof importScripts == "function";
var ENVIRONMENT_IS_NODE = typeof process == "object" && typeof process.versions == "object" && typeof process.versions.node == "string";
var ENVIRONMENT_IS_PTHREAD = Module["ENVIRONMENT_IS_PTHREAD"] || false;
var _scriptDir = typeof document != "undefined" && document.currentScript ? document.currentScript.src : undefined;
if (ENVIRONMENT_IS_WORKER) {
  _scriptDir = self.location.href
} else if (ENVIRONMENT_IS_NODE) {
  _scriptDir = __filename
}
var scriptDirectory = "";

function locateFile(path) {
  if (Module["locateFile"]) {
    return Module["locateFile"](path, scriptDirectory)
  }
  return scriptDirectory + path
}
var read_, readAsync, readBinary;
if (ENVIRONMENT_IS_NODE) {
  var fs = require("fs");
  var nodePath = require("path");
  if (ENVIRONMENT_IS_WORKER) {
    scriptDirectory = nodePath.dirname(scriptDirectory) + "/"
  } else {
    scriptDirectory = __dirname + "/"
  }
  read_ = (filename, binary) => {
    filename = isFileURI(filename) ? new URL(filename) : nodePath.normalize(filename);
    return fs.readFileSync(filename, binary ? undefined : "utf8")
  };
  readBinary = filename => {
    var ret = read_(filename, true);
    if (!ret.buffer) {
      ret = new Uint8Array(ret)
    }
    return ret
  };
  readAsync = (filename, onload, onerror, binary = true) => {
    filename = isFileURI(filename) ? new URL(filename) : nodePath.normalize(filename);
    fs.readFile(filename, binary ? undefined : "utf8", (err, data) => {
      if (err) onerror(err);
      else onload(binary ? data.buffer : data)
    })
  };
  if (!Module["thisProgram"] && process.argv.length > 1) {
    thisProgram = process.argv[1].replace(/\\/g, "/")
  }
  arguments_ = process.argv.slice(2);
  if (typeof module != "undefined") {
    module["exports"] = Module
  }
  process.on("uncaughtException", ex => {
    if (ex !== "unwind" && !(ex instanceof ExitStatus) && !(ex.context instanceof ExitStatus)) {
      throw ex
    }
  });
  quit_ = (status, toThrow) => {
    process.exitCode = status;
    throw toThrow
  };
  Module["inspect"] = () => "[Emscripten Module object]";
  let nodeWorkerThreads;
  try {
    nodeWorkerThreads = require("worker_threads")
  } catch (e) {
    console.error('The "worker_threads" module is not supported in this node.js build - perhaps a newer version is needed?');
    throw e
  }
  global.Worker = nodeWorkerThreads.Worker
} else if (ENVIRONMENT_IS_WEB || ENVIRONMENT_IS_WORKER) {
  if (ENVIRONMENT_IS_WORKER) {
    scriptDirectory = self.location.href
  } else if (typeof document != "undefined" && document.currentScript) {
    scriptDirectory = document.currentScript.src
  }
  if (scriptDirectory.indexOf("blob:") !== 0) {
    scriptDirectory = scriptDirectory.substr(0, scriptDirectory.replace(/[?#].*/, "").lastIndexOf("/") + 1)
  } else {
    scriptDirectory = ""
  }
  if (!ENVIRONMENT_IS_NODE) {
    read_ = url => {
      var xhr = new XMLHttpRequest;
      xhr.open("GET", url, false);
      xhr.send(null);
      return xhr.responseText
    };
    if (ENVIRONMENT_IS_WORKER) {
      readBinary = url => {
        var xhr = new XMLHttpRequest;
        xhr.open("GET", url, false);
        xhr.responseType = "arraybuffer";
        xhr.send(null);
        return new Uint8Array(xhr.response)
      }
    }
    readAsync = (url, onload, onerror) => {
      var xhr = new XMLHttpRequest;
      xhr.open("GET", url, true);
      xhr.responseType = "arraybuffer";
      xhr.onload = () => {
        if (xhr.status == 200 || xhr.status == 0 && xhr.response) {
          onload(xhr.response);
          return
        }
        onerror()
      };
      xhr.onerror = onerror;
      xhr.send(null)
    }
  }
} else {}
if (ENVIRONMENT_IS_NODE) {
  if (typeof performance == "undefined") {
    global.performance = require("perf_hooks").performance
  }
}
var defaultPrint = console.log.bind(console);
var defaultPrintErr = console.error.bind(console);
if (ENVIRONMENT_IS_NODE) {
  defaultPrint = (...args) => fs.writeSync(1, args.join(" ") + "\n");
  defaultPrintErr = (...args) => fs.writeSync(2, args.join(" ") + "\n")
}
var out = Module["print"] || defaultPrint;
var err = Module["printErr"] || defaultPrintErr;
Object.assign(Module, moduleOverrides);
moduleOverrides = null;
if (Module["arguments"]) arguments_ = Module["arguments"];
if (Module["thisProgram"]) thisProgram = Module["thisProgram"];
if (Module["quit"]) quit_ = Module["quit"];
var wasmBinary;
if (Module["wasmBinary"]) wasmBinary = Module["wasmBinary"];
if (typeof WebAssembly != "object") {
  abort("no native wasm support detected")
}
var wasmMemory;
var wasmModule;
var ABORT = false;
var EXITSTATUS;

function assert(condition, text) {
  if (!condition) {
    abort(text)
  }
}
var HEAP8, HEAPU8, HEAP16, HEAPU16, HEAP32, HEAPU32, HEAPF32, HEAPF64;

function updateMemoryViews() {
  var b = wasmMemory.buffer;
  Module["HEAP8"] = HEAP8 = new Int8Array(b);
  Module["HEAP16"] = HEAP16 = new Int16Array(b);
  Module["HEAPU8"] = HEAPU8 = new Uint8Array(b);
  Module["HEAPU16"] = HEAPU16 = new Uint16Array(b);
  Module["HEAP32"] = HEAP32 = new Int32Array(b);
  Module["HEAPU32"] = HEAPU32 = new Uint32Array(b);
  Module["HEAPF32"] = HEAPF32 = new Float32Array(b);
  Module["HEAPF64"] = HEAPF64 = new Float64Array(b)
}
var INITIAL_MEMORY = Module["INITIAL_MEMORY"] || 33554432;
assert(INITIAL_MEMORY >= 5242880, "INITIAL_MEMORY should be larger than STACK_SIZE, was " + INITIAL_MEMORY + "! (STACK_SIZE=" + 5242880 + ")");
if (ENVIRONMENT_IS_PTHREAD) {
  wasmMemory = Module["wasmMemory"]
} else {
  if (Module["wasmMemory"]) {
    wasmMemory = Module["wasmMemory"]
  } else {
    wasmMemory = new WebAssembly.Memory({
      "initial": INITIAL_MEMORY / 65536,
      "maximum": 2130706432 / 65536,
      "shared": true
    });
    if (!(wasmMemory.buffer instanceof SharedArrayBuffer)) {
      err("requested a shared WebAssembly.Memory but the returned buffer is not a SharedArrayBuffer, indicating that while the browser has SharedArrayBuffer it does not have WebAssembly threads support - you may need to set a flag");
      if (ENVIRONMENT_IS_NODE) {
        err("(on node you may need: --experimental-wasm-threads --experimental-wasm-bulk-memory and/or recent version)")
      }
      throw Error("bad memory")
    }
  }
}
updateMemoryViews();
INITIAL_MEMORY = wasmMemory.buffer.byteLength;
var __ATPRERUN__ = [];
var __ATINIT__ = [];
var __ATMAIN__ = [];
var __ATEXIT__ = [];
var __ATPOSTRUN__ = [];
var runtimeInitialized = false;

function preRun() {
  if (Module["preRun"]) {
    if (typeof Module["preRun"] == "function") Module["preRun"] = [Module["preRun"]];
    while (Module["preRun"].length) {
      addOnPreRun(Module["preRun"].shift())
    }
  }
  callRuntimeCallbacks(__ATPRERUN__)
}

function initRuntime() {
  runtimeInitialized = true;
  if (ENVIRONMENT_IS_PTHREAD) return;
  if (!Module["noFSInit"] && !FS.init.initialized) FS.init();
  FS.ignorePermissions = false;
  TTY.init();
  callRuntimeCallbacks(__ATINIT__)
}

function preMain() {
  if (ENVIRONMENT_IS_PTHREAD) return;
  callRuntimeCallbacks(__ATMAIN__)
}

function postRun() {
  if (ENVIRONMENT_IS_PTHREAD) return;
  if (Module["postRun"]) {
    if (typeof Module["postRun"] == "function") Module["postRun"] = [Module["postRun"]];
    while (Module["postRun"].length) {
      addOnPostRun(Module["postRun"].shift())
    }
  }
  callRuntimeCallbacks(__ATPOSTRUN__)
}

function addOnPreRun(cb) {
  __ATPRERUN__.unshift(cb)
}

function addOnInit(cb) {
  __ATINIT__.unshift(cb)
}

function addOnPostRun(cb) {
  __ATPOSTRUN__.unshift(cb)
}
var runDependencies = 0;
var runDependencyWatcher = null;
var dependenciesFulfilled = null;

function getUniqueRunDependency(id) {
  return id
}

function addRunDependency(id) {
  runDependencies++;
  if (Module["monitorRunDependencies"]) {
    Module["monitorRunDependencies"](runDependencies)
  }
}

function removeRunDependency(id) {
  runDependencies--;
  if (Module["monitorRunDependencies"]) {
    Module["monitorRunDependencies"](runDependencies)
  }
  if (runDependencies == 0) {
    if (runDependencyWatcher !== null) {
      clearInterval(runDependencyWatcher);
      runDependencyWatcher = null
    }
    if (dependenciesFulfilled) {
      var callback = dependenciesFulfilled;
      dependenciesFulfilled = null;
      callback()
    }
  }
}

function abort(what) {
  if (Module["onAbort"]) {
    Module["onAbort"](what)
  }
  what = "Aborted(" + what + ")";
  err(what);
  ABORT = true;
  EXITSTATUS = 1;
  what += ". Build with -sASSERTIONS for more info.";
  var e = new WebAssembly.RuntimeError(what);
  throw e
}
var dataURIPrefix = "data:application/octet-stream;base64,";
var isDataURI = filename => filename.startsWith(dataURIPrefix);
var isFileURI = filename => filename.startsWith("file://");
var wasmBinaryFile;
wasmBinaryFile = "RenderCoreEngine.wasm";
if (!isDataURI(wasmBinaryFile)) {
  wasmBinaryFile = locateFile(wasmBinaryFile)
}

function getBinarySync(file) {
  if (file == wasmBinaryFile && wasmBinary) {
    return new Uint8Array(wasmBinary)
  }
  if (readBinary) {
    return readBinary(file)
  }
  throw "both async and sync fetching of the wasm failed"
}

function getBinaryPromise(binaryFile) {
  if (!wasmBinary && (ENVIRONMENT_IS_WEB || ENVIRONMENT_IS_WORKER)) {
    if (typeof fetch == "function" && !isFileURI(binaryFile)) {
      return fetch(binaryFile, {
        credentials: "same-origin"
      }).then(response => {
        if (!response["ok"]) {
          throw "failed to load wasm binary file at '" + binaryFile + "'"
        }
        return response["arrayBuffer"]()
      }).catch(() => getBinarySync(binaryFile))
    } else if (readAsync) {
      return new Promise((resolve, reject) => {
        readAsync(binaryFile, response => resolve(new Uint8Array(response)), reject)
      })
    }
  }
  return Promise.resolve().then(() => getBinarySync(binaryFile))
}

function instantiateArrayBuffer(binaryFile, imports, receiver) {
  return getBinaryPromise(binaryFile).then(binary => WebAssembly.instantiate(binary, imports)).then(instance => instance).then(receiver, reason => {
    err(`failed to asynchronously prepare wasm: ${reason}`);
    abort(reason)
  })
}

function instantiateAsync(binary, binaryFile, imports, callback) {
  if (!binary && typeof WebAssembly.instantiateStreaming == "function" && !isDataURI(binaryFile) && !isFileURI(binaryFile) && !ENVIRONMENT_IS_NODE && typeof fetch == "function") {
    return fetch(binaryFile, {
      credentials: "same-origin"
    }).then(response => {
      var result = WebAssembly.instantiateStreaming(response, imports);
      return result.then(callback, function (reason) {
        err(`wasm streaming compile failed: ${reason}`);
        err("falling back to ArrayBuffer instantiation");
        return instantiateArrayBuffer(binaryFile, imports, callback)
      })
    })
  }
  return instantiateArrayBuffer(binaryFile, imports, callback)
}

function createWasm() {
  var info = {
    "a": wasmImports
  };

  function receiveInstance(instance, module) {
    wasmExports = instance.exports;
    registerTLSInit(wasmExports["R"]);
    wasmTable = wasmExports["Q"];
    addOnInit(wasmExports["O"]);
    wasmModule = module;
    removeRunDependency("wasm-instantiate");
    return wasmExports
  }
  addRunDependency("wasm-instantiate");

  function receiveInstantiationResult(result) {
    receiveInstance(result["instance"], result["module"])
  }
  if (Module["instantiateWasm"]) {
    try {
      return Module["instantiateWasm"](info, receiveInstance)
    } catch (e) {
      err(`Module.instantiateWasm callback failed with error: ${e}`);
      return false
    }
  }
  instantiateAsync(wasmBinary, wasmBinaryFile, info, receiveInstantiationResult);
  return {}
}
var tempDouble;
var tempI64;

function ExitStatus(status) {
  this.name = "ExitStatus";
  this.message = `Program terminated with exit(${status})`;
  this.status = status
}
var terminateWorker = worker => {
  worker.terminate();
  worker.onmessage = e => {}
};
var killThread = pthread_ptr => {
  var worker = PThread.pthreads[pthread_ptr];
  delete PThread.pthreads[pthread_ptr];
  terminateWorker(worker);
  __emscripten_thread_free_data(pthread_ptr);
  PThread.runningWorkers.splice(PThread.runningWorkers.indexOf(worker), 1);
  worker.pthread_ptr = 0
};
var cancelThread = pthread_ptr => {
  var worker = PThread.pthreads[pthread_ptr];
  worker.postMessage({
    "cmd": "cancel"
  })
};
var cleanupThread = pthread_ptr => {
  var worker = PThread.pthreads[pthread_ptr];
  assert(worker);
  PThread.returnWorkerToPool(worker)
};
var spawnThread = threadParams => {
  var worker = PThread.getNewWorker();
  if (!worker) {
    return 6
  }
  PThread.runningWorkers.push(worker);
  PThread.pthreads[threadParams.pthread_ptr] = worker;
  worker.pthread_ptr = threadParams.pthread_ptr;
  var msg = {
    "cmd": "run",
    "start_routine": threadParams.startRoutine,
    "arg": threadParams.arg,
    "pthread_ptr": threadParams.pthread_ptr
  };
  if (ENVIRONMENT_IS_NODE) {
    worker.unref()
  }
  worker.postMessage(msg, threadParams.transferList);
  return 0
};
var runtimeKeepaliveCounter = 0;
var keepRuntimeAlive = () => noExitRuntime || runtimeKeepaliveCounter > 0;
var PATH = {
  isAbs: path => path.charAt(0) === "/",
  splitPath: filename => {
    var splitPathRe = /^(\/?|)([\s\S]*?)((?:\.{1,2}|[^\/]+?|)(\.[^.\/]*|))(?:[\/]*)$/;
    return splitPathRe.exec(filename).slice(1)
  },
  normalizeArray: (parts, allowAboveRoot) => {
    var up = 0;
    for (var i = parts.length - 1; i >= 0; i--) {
      var last = parts[i];
      if (last === ".") {
        parts.splice(i, 1)
      } else if (last === "..") {
        parts.splice(i, 1);
        up++
      } else if (up) {
        parts.splice(i, 1);
        up--
      }
    }
    if (allowAboveRoot) {
      for (; up; up--) {
        parts.unshift("..")
      }
    }
    return parts
  },
  normalize: path => {
    var isAbsolute = PATH.isAbs(path),
      trailingSlash = path.substr(-1) === "/";
    path = PATH.normalizeArray(path.split("/").filter(p => !!p), !isAbsolute).join("/");
    if (!path && !isAbsolute) {
      path = "."
    }
    if (path && trailingSlash) {
      path += "/"
    }
    return (isAbsolute ? "/" : "") + path
  },
  dirname: path => {
    var result = PATH.splitPath(path),
      root = result[0],
      dir = result[1];
    if (!root && !dir) {
      return "."
    }
    if (dir) {
      dir = dir.substr(0, dir.length - 1)
    }
    return root + dir
  },
  basename: path => {
    if (path === "/") return "/";
    path = PATH.normalize(path);
    path = path.replace(/\/$/, "");
    var lastSlash = path.lastIndexOf("/");
    if (lastSlash === -1) return path;
    return path.substr(lastSlash + 1)
  },
  join: function () {
    var paths = Array.prototype.slice.call(arguments);
    return PATH.normalize(paths.join("/"))
  },
  join2: (l, r) => PATH.normalize(l + "/" + r)
};
var initRandomFill = () => {
  if (typeof crypto == "object" && typeof crypto["getRandomValues"] == "function") {
    return view => (view.set(crypto.getRandomValues(new Uint8Array(view.byteLength))), view)
  } else if (ENVIRONMENT_IS_NODE) {
    try {
      var crypto_module = require("crypto");
      var randomFillSync = crypto_module["randomFillSync"];
      if (randomFillSync) {
        return view => crypto_module["randomFillSync"](view)
      }
      var randomBytes = crypto_module["randomBytes"];
      return view => (view.set(randomBytes(view.byteLength)), view)
    } catch (e) {}
  }
  abort("initRandomDevice")
};
var randomFill = view => (randomFill = initRandomFill())(view);
var PATH_FS = {
  resolve: function () {
    var resolvedPath = "",
      resolvedAbsolute = false;
    for (var i = arguments.length - 1; i >= -1 && !resolvedAbsolute; i--) {
      var path = i >= 0 ? arguments[i] : FS.cwd();
      if (typeof path != "string") {
        throw new TypeError("Arguments to path.resolve must be strings")
      } else if (!path) {
        return ""
      }
      resolvedPath = path + "/" + resolvedPath;
      resolvedAbsolute = PATH.isAbs(path)
    }
    resolvedPath = PATH.normalizeArray(resolvedPath.split("/").filter(p => !!p), !resolvedAbsolute).join("/");
    return (resolvedAbsolute ? "/" : "") + resolvedPath || "."
  },
  relative: (from, to) => {
    from = PATH_FS.resolve(from).substr(1);
    to = PATH_FS.resolve(to).substr(1);

    function trim(arr) {
      var start = 0;
      for (; start < arr.length; start++) {
        if (arr[start] !== "") break
      }
      var end = arr.length - 1;
      for (; end >= 0; end--) {
        if (arr[end] !== "") break
      }
      if (start > end) return [];
      return arr.slice(start, end - start + 1)
    }
    var fromParts = trim(from.split("/"));
    var toParts = trim(to.split("/"));
    var length = Math.min(fromParts.length, toParts.length);
    var samePartsLength = length;
    for (var i = 0; i < length; i++) {
      if (fromParts[i] !== toParts[i]) {
        samePartsLength = i;
        break
      }
    }
    var outputParts = [];
    for (var i = samePartsLength; i < fromParts.length; i++) {
      outputParts.push("..")
    }
    outputParts = outputParts.concat(toParts.slice(samePartsLength));
    return outputParts.join("/")
  }
};
var UTF8Decoder = typeof TextDecoder != "undefined" ? new TextDecoder("utf8") : undefined;
var UTF8ArrayToString = (heapOrArray, idx, maxBytesToRead) => {
  var endIdx = idx + maxBytesToRead;
  var endPtr = idx;
  while (heapOrArray[endPtr] && !(endPtr >= endIdx)) ++endPtr;
  if (endPtr - idx > 16 && heapOrArray.buffer && UTF8Decoder) {
    return UTF8Decoder.decode(heapOrArray.buffer instanceof SharedArrayBuffer ? heapOrArray.slice(idx, endPtr) : heapOrArray.subarray(idx, endPtr))
  }
  var str = "";
  while (idx < endPtr) {
    var u0 = heapOrArray[idx++];
    if (!(u0 & 128)) {
      str += String.fromCharCode(u0);
      continue
    }
    var u1 = heapOrArray[idx++] & 63;
    if ((u0 & 224) == 192) {
      str += String.fromCharCode((u0 & 31) << 6 | u1);
      continue
    }
    var u2 = heapOrArray[idx++] & 63;
    if ((u0 & 240) == 224) {
      u0 = (u0 & 15) << 12 | u1 << 6 | u2
    } else {
      u0 = (u0 & 7) << 18 | u1 << 12 | u2 << 6 | heapOrArray[idx++] & 63
    }
    if (u0 < 65536) {
      str += String.fromCharCode(u0)
    } else {
      var ch = u0 - 65536;
      str += String.fromCharCode(55296 | ch >> 10, 56320 | ch & 1023)
    }
  }
  return str
};
var FS_stdin_getChar_buffer = [];
var lengthBytesUTF8 = str => {
  var len = 0;
  for (var i = 0; i < str.length; ++i) {
    var c = str.charCodeAt(i);
    if (c <= 127) {
      len++
    } else if (c <= 2047) {
      len += 2
    } else if (c >= 55296 && c <= 57343) {
      len += 4;
      ++i
    } else {
      len += 3
    }
  }
  return len
};
var stringToUTF8Array = (str, heap, outIdx, maxBytesToWrite) => {
  if (!(maxBytesToWrite > 0)) return 0;
  var startIdx = outIdx;
  var endIdx = outIdx + maxBytesToWrite - 1;
  for (var i = 0; i < str.length; ++i) {
    var u = str.charCodeAt(i);
    if (u >= 55296 && u <= 57343) {
      var u1 = str.charCodeAt(++i);
      u = 65536 + ((u & 1023) << 10) | u1 & 1023
    }
    if (u <= 127) {
      if (outIdx >= endIdx) break;
      heap[outIdx++] = u
    } else if (u <= 2047) {
      if (outIdx + 1 >= endIdx) break;
      heap[outIdx++] = 192 | u >> 6;
      heap[outIdx++] = 128 | u & 63
    } else if (u <= 65535) {
      if (outIdx + 2 >= endIdx) break;
      heap[outIdx++] = 224 | u >> 12;
      heap[outIdx++] = 128 | u >> 6 & 63;
      heap[outIdx++] = 128 | u & 63
    } else {
      if (outIdx + 3 >= endIdx) break;
      heap[outIdx++] = 240 | u >> 18;
      heap[outIdx++] = 128 | u >> 12 & 63;
      heap[outIdx++] = 128 | u >> 6 & 63;
      heap[outIdx++] = 128 | u & 63
    }
  }
  heap[outIdx] = 0;
  return outIdx - startIdx
};

function intArrayFromString(stringy, dontAddNull, length) {
  var len = length > 0 ? length : lengthBytesUTF8(stringy) + 1;
  var u8array = new Array(len);
  var numBytesWritten = stringToUTF8Array(stringy, u8array, 0, u8array.length);
  if (dontAddNull) u8array.length = numBytesWritten;
  return u8array
}
var FS_stdin_getChar = () => {
  if (!FS_stdin_getChar_buffer.length) {
    var result = null;
    if (ENVIRONMENT_IS_NODE) {
      var BUFSIZE = 256;
      var buf = Buffer.alloc(BUFSIZE);
      var bytesRead = 0;
      var fd = process.stdin.fd;
      try {
        bytesRead = fs.readSync(fd, buf)
      } catch (e) {
        if (e.toString().includes("EOF")) bytesRead = 0;
        else throw e
      }
      if (bytesRead > 0) {
        result = buf.slice(0, bytesRead).toString("utf-8")
      } else {
        result = null
      }
    } else if (typeof window != "undefined" && typeof window.prompt == "function") {
      result = window.prompt("Input: ");
      if (result !== null) {
        result += "\n"
      }
    } else if (typeof readline == "function") {
      result = readline();
      if (result !== null) {
        result += "\n"
      }
    }
    if (!result) {
      return null
    }
    FS_stdin_getChar_buffer = intArrayFromString(result, true)
  }
  return FS_stdin_getChar_buffer.shift()
};
var TTY = {
  ttys: [],
  init() {},
  shutdown() {},
  register(dev, ops) {
    TTY.ttys[dev] = {
      input: [],
      output: [],
      ops: ops
    };
    FS.registerDevice(dev, TTY.stream_ops)
  },
  stream_ops: {
    open(stream) {
      var tty = TTY.ttys[stream.node.rdev];
      if (!tty) {
        throw new FS.ErrnoError(43)
      }
      stream.tty = tty;
      stream.seekable = false
    },
    close(stream) {
      stream.tty.ops.fsync(stream.tty)
    },
    fsync(stream) {
      stream.tty.ops.fsync(stream.tty)
    },
    read(stream, buffer, offset, length, pos) {
      if (!stream.tty || !stream.tty.ops.get_char) {
        throw new FS.ErrnoError(60)
      }
      var bytesRead = 0;
      for (var i = 0; i < length; i++) {
        var result;
        try {
          result = stream.tty.ops.get_char(stream.tty)
        } catch (e) {
          throw new FS.ErrnoError(29)
        }
        if (result === undefined && bytesRead === 0) {
          throw new FS.ErrnoError(6)
        }
        if (result === null || result === undefined) break;
        bytesRead++;
        buffer[offset + i] = result
      }
      if (bytesRead) {
        stream.node.timestamp = Date.now()
      }
      return bytesRead
    },
    write(stream, buffer, offset, length, pos) {
      if (!stream.tty || !stream.tty.ops.put_char) {
        throw new FS.ErrnoError(60)
      }
      try {
        for (var i = 0; i < length; i++) {
          stream.tty.ops.put_char(stream.tty, buffer[offset + i])
        }
      } catch (e) {
        throw new FS.ErrnoError(29)
      }
      if (length) {
        stream.node.timestamp = Date.now()
      }
      return i
    }
  },
  default_tty_ops: {
    get_char(tty) {
      return FS_stdin_getChar()
    },
    put_char(tty, val) {
      if (val === null || val === 10) {
        out(UTF8ArrayToString(tty.output, 0));
        tty.output = []
      } else {
        if (val != 0) tty.output.push(val)
      }
    },
    fsync(tty) {
      if (tty.output && tty.output.length > 0) {
        out(UTF8ArrayToString(tty.output, 0));
        tty.output = []
      }
    },
    ioctl_tcgets(tty) {
      return {
        c_iflag: 25856,
        c_oflag: 5,
        c_cflag: 191,
        c_lflag: 35387,
        c_cc: [3, 28, 127, 21, 4, 0, 1, 0, 17, 19, 26, 0, 18, 15, 23, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
      }
    },
    ioctl_tcsets(tty, optional_actions, data) {
      return 0
    },
    ioctl_tiocgwinsz(tty) {
      return [24, 80]
    }
  },
  default_tty1_ops: {
    put_char(tty, val) {
      if (val === null || val === 10) {
        err(UTF8ArrayToString(tty.output, 0));
        tty.output = []
      } else {
        if (val != 0) tty.output.push(val)
      }
    },
    fsync(tty) {
      if (tty.output && tty.output.length > 0) {
        err(UTF8ArrayToString(tty.output, 0));
        tty.output = []
      }
    }
  }
};
var mmapAlloc = size => {
  abort()
};
var MEMFS = {
  ops_table: null,
  mount(mount) {
    return MEMFS.createNode(null, "/", 16384 | 511, 0)
  },
  createNode(parent, name, mode, dev) {
    if (FS.isBlkdev(mode) || FS.isFIFO(mode)) {
      throw new FS.ErrnoError(63)
    }
    if (!MEMFS.ops_table) {
      MEMFS.ops_table = {
        dir: {
          node: {
            getattr: MEMFS.node_ops.getattr,
            setattr: MEMFS.node_ops.setattr,
            lookup: MEMFS.node_ops.lookup,
            mknod: MEMFS.node_ops.mknod,
            rename: MEMFS.node_ops.rename,
            unlink: MEMFS.node_ops.unlink,
            rmdir: MEMFS.node_ops.rmdir,
            readdir: MEMFS.node_ops.readdir,
            symlink: MEMFS.node_ops.symlink
          },
          stream: {
            llseek: MEMFS.stream_ops.llseek
          }
        },
        file: {
          node: {
            getattr: MEMFS.node_ops.getattr,
            setattr: MEMFS.node_ops.setattr
          },
          stream: {
            llseek: MEMFS.stream_ops.llseek,
            read: MEMFS.stream_ops.read,
            write: MEMFS.stream_ops.write,
            allocate: MEMFS.stream_ops.allocate,
            mmap: MEMFS.stream_ops.mmap,
            msync: MEMFS.stream_ops.msync
          }
        },
        link: {
          node: {
            getattr: MEMFS.node_ops.getattr,
            setattr: MEMFS.node_ops.setattr,
            readlink: MEMFS.node_ops.readlink
          },
          stream: {}
        },
        chrdev: {
          node: {
            getattr: MEMFS.node_ops.getattr,
            setattr: MEMFS.node_ops.setattr
          },
          stream: FS.chrdev_stream_ops
        }
      }
    }
    var node = FS.createNode(parent, name, mode, dev);
    if (FS.isDir(node.mode)) {
      node.node_ops = MEMFS.ops_table.dir.node;
      node.stream_ops = MEMFS.ops_table.dir.stream;
      node.contents = {}
    } else if (FS.isFile(node.mode)) {
      node.node_ops = MEMFS.ops_table.file.node;
      node.stream_ops = MEMFS.ops_table.file.stream;
      node.usedBytes = 0;
      node.contents = null
    } else if (FS.isLink(node.mode)) {
      node.node_ops = MEMFS.ops_table.link.node;
      node.stream_ops = MEMFS.ops_table.link.stream
    } else if (FS.isChrdev(node.mode)) {
      node.node_ops = MEMFS.ops_table.chrdev.node;
      node.stream_ops = MEMFS.ops_table.chrdev.stream
    }
    node.timestamp = Date.now();
    if (parent) {
      parent.contents[name] = node;
      parent.timestamp = node.timestamp
    }
    return node
  },
  getFileDataAsTypedArray(node) {
    if (!node.contents) return new Uint8Array(0);
    if (node.contents.subarray) return node.contents.subarray(0, node.usedBytes);
    return new Uint8Array(node.contents)
  },
  expandFileStorage(node, newCapacity) {
    var prevCapacity = node.contents ? node.contents.length : 0;
    if (prevCapacity >= newCapacity) return;
    var CAPACITY_DOUBLING_MAX = 1024 * 1024;
    newCapacity = Math.max(newCapacity, prevCapacity * (prevCapacity < CAPACITY_DOUBLING_MAX ? 2 : 1.125) >>> 0);
    if (prevCapacity != 0) newCapacity = Math.max(newCapacity, 256);
    var oldContents = node.contents;
    node.contents = new Uint8Array(newCapacity);
    if (node.usedBytes > 0) node.contents.set(oldContents.subarray(0, node.usedBytes), 0)
  },
  resizeFileStorage(node, newSize) {
    if (node.usedBytes == newSize) return;
    if (newSize == 0) {
      node.contents = null;
      node.usedBytes = 0
    } else {
      var oldContents = node.contents;
      node.contents = new Uint8Array(newSize);
      if (oldContents) {
        node.contents.set(oldContents.subarray(0, Math.min(newSize, node.usedBytes)))
      }
      node.usedBytes = newSize
    }
  },
  node_ops: {
    getattr(node) {
      var attr = {};
      attr.dev = FS.isChrdev(node.mode) ? node.id : 1;
      attr.ino = node.id;
      attr.mode = node.mode;
      attr.nlink = 1;
      attr.uid = 0;
      attr.gid = 0;
      attr.rdev = node.rdev;
      if (FS.isDir(node.mode)) {
        attr.size = 4096
      } else if (FS.isFile(node.mode)) {
        attr.size = node.usedBytes
      } else if (FS.isLink(node.mode)) {
        attr.size = node.link.length
      } else {
        attr.size = 0
      }
      attr.atime = new Date(node.timestamp);
      attr.mtime = new Date(node.timestamp);
      attr.ctime = new Date(node.timestamp);
      attr.blksize = 4096;
      attr.blocks = Math.ceil(attr.size / attr.blksize);
      return attr
    },
    setattr(node, attr) {
      if (attr.mode !== undefined) {
        node.mode = attr.mode
      }
      if (attr.timestamp !== undefined) {
        node.timestamp = attr.timestamp
      }
      if (attr.size !== undefined) {
        MEMFS.resizeFileStorage(node, attr.size)
      }
    },
    lookup(parent, name) {
      throw FS.genericErrors[44]
    },
    mknod(parent, name, mode, dev) {
      return MEMFS.createNode(parent, name, mode, dev)
    },
    rename(old_node, new_dir, new_name) {
      if (FS.isDir(old_node.mode)) {
        var new_node;
        try {
          new_node = FS.lookupNode(new_dir, new_name)
        } catch (e) {}
        if (new_node) {
          for (var i in new_node.contents) {
            throw new FS.ErrnoError(55)
          }
        }
      }
      delete old_node.parent.contents[old_node.name];
      old_node.parent.timestamp = Date.now();
      old_node.name = new_name;
      new_dir.contents[new_name] = old_node;
      new_dir.timestamp = old_node.parent.timestamp;
      old_node.parent = new_dir
    },
    unlink(parent, name) {
      delete parent.contents[name];
      parent.timestamp = Date.now()
    },
    rmdir(parent, name) {
      var node = FS.lookupNode(parent, name);
      for (var i in node.contents) {
        throw new FS.ErrnoError(55)
      }
      delete parent.contents[name];
      parent.timestamp = Date.now()
    },
    readdir(node) {
      var entries = [".", ".."];
      for (var key in node.contents) {
        if (!node.contents.hasOwnProperty(key)) {
          continue
        }
        entries.push(key)
      }
      return entries
    },
    symlink(parent, newname, oldpath) {
      var node = MEMFS.createNode(parent, newname, 511 | 40960, 0);
      node.link = oldpath;
      return node
    },
    readlink(node) {
      if (!FS.isLink(node.mode)) {
        throw new FS.ErrnoError(28)
      }
      return node.link
    }
  },
  stream_ops: {
    read(stream, buffer, offset, length, position) {
      var contents = stream.node.contents;
      if (position >= stream.node.usedBytes) return 0;
      var size = Math.min(stream.node.usedBytes - position, length);
      if (size > 8 && contents.subarray) {
        buffer.set(contents.subarray(position, position + size), offset)
      } else {
        for (var i = 0; i < size; i++) buffer[offset + i] = contents[position + i]
      }
      return size
    },
    write(stream, buffer, offset, length, position, canOwn) {
      if (buffer.buffer === GROWABLE_HEAP_I8().buffer) {
        canOwn = false
      }
      if (!length) return 0;
      var node = stream.node;
      node.timestamp = Date.now();
      if (buffer.subarray && (!node.contents || node.contents.subarray)) {
        if (canOwn) {
          node.contents = buffer.subarray(offset, offset + length);
          node.usedBytes = length;
          return length
        } else if (node.usedBytes === 0 && position === 0) {
          node.contents = buffer.slice(offset, offset + length);
          node.usedBytes = length;
          return length
        } else if (position + length <= node.usedBytes) {
          node.contents.set(buffer.subarray(offset, offset + length), position);
          return length
        }
      }
      MEMFS.expandFileStorage(node, position + length);
      if (node.contents.subarray && buffer.subarray) {
        node.contents.set(buffer.subarray(offset, offset + length), position)
      } else {
        for (var i = 0; i < length; i++) {
          node.contents[position + i] = buffer[offset + i]
        }
      }
      node.usedBytes = Math.max(node.usedBytes, position + length);
      return length
    },
    llseek(stream, offset, whence) {
      var position = offset;
      if (whence === 1) {
        position += stream.position
      } else if (whence === 2) {
        if (FS.isFile(stream.node.mode)) {
          position += stream.node.usedBytes
        }
      }
      if (position < 0) {
        throw new FS.ErrnoError(28)
      }
      return position
    },
    allocate(stream, offset, length) {
      MEMFS.expandFileStorage(stream.node, offset + length);
      stream.node.usedBytes = Math.max(stream.node.usedBytes, offset + length)
    },
    mmap(stream, length, position, prot, flags) {
      if (!FS.isFile(stream.node.mode)) {
        throw new FS.ErrnoError(43)
      }
      var ptr;
      var allocated;
      var contents = stream.node.contents;
      if (!(flags & 2) && contents.buffer === GROWABLE_HEAP_I8().buffer) {
        allocated = false;
        ptr = contents.byteOffset
      } else {
        if (position > 0 || position + length < contents.length) {
          if (contents.subarray) {
            contents = contents.subarray(position, position + length)
          } else {
            contents = Array.prototype.slice.call(contents, position, position + length)
          }
        }
        allocated = true;
        ptr = mmapAlloc(length);
        if (!ptr) {
          throw new FS.ErrnoError(48)
        }
        GROWABLE_HEAP_I8().set(contents, ptr)
      }
      return {
        ptr: ptr,
        allocated: allocated
      }
    },
    msync(stream, buffer, offset, length, mmapFlags) {
      MEMFS.stream_ops.write(stream, buffer, 0, length, offset, false);
      return 0
    }
  }
};
var asyncLoad = (url, onload, onerror, noRunDep) => {
  var dep = !noRunDep ? getUniqueRunDependency(`al ${url}`) : "";
  readAsync(url, arrayBuffer => {
    assert(arrayBuffer, `Loading data file "${url}" failed (no arrayBuffer).`);
    onload(new Uint8Array(arrayBuffer));
    if (dep) removeRunDependency(dep)
  }, event => {
    if (onerror) {
      onerror()
    } else {
      throw `Loading data file "${url}" failed.`
    }
  });
  if (dep) addRunDependency(dep)
};
var FS_createDataFile = (parent, name, fileData, canRead, canWrite, canOwn) => FS.createDataFile(parent, name, fileData, canRead, canWrite, canOwn);
var preloadPlugins = Module["preloadPlugins"] || [];
var FS_handledByPreloadPlugin = (byteArray, fullname, finish, onerror) => {
  if (typeof Browser != "undefined") Browser.init();
  var handled = false;
  preloadPlugins.forEach(plugin => {
    if (handled) return;
    if (plugin["canHandle"](fullname)) {
      plugin["handle"](byteArray, fullname, finish, onerror);
      handled = true
    }
  });
  return handled
};
var FS_createPreloadedFile = (parent, name, url, canRead, canWrite, onload, onerror, dontCreateFile, canOwn, preFinish) => {
  var fullname = name ? PATH_FS.resolve(PATH.join2(parent, name)) : parent;
  var dep = getUniqueRunDependency(`cp ${fullname}`);

  function processData(byteArray) {
    function finish(byteArray) {
      if (preFinish) preFinish();
      if (!dontCreateFile) {
        FS_createDataFile(parent, name, byteArray, canRead, canWrite, canOwn)
      }
      if (onload) onload();
      removeRunDependency(dep)
    }
    if (FS_handledByPreloadPlugin(byteArray, fullname, finish, () => {
        if (onerror) onerror();
        removeRunDependency(dep)
      })) {
      return
    }
    finish(byteArray)
  }
  addRunDependency(dep);
  if (typeof url == "string") {
    asyncLoad(url, byteArray => processData(byteArray), onerror)
  } else {
    processData(url)
  }
};
var FS_modeStringToFlags = str => {
  var flagModes = {
    "r": 0,
    "r+": 2,
    "w": 512 | 64 | 1,
    "w+": 512 | 64 | 2,
    "a": 1024 | 64 | 1,
    "a+": 1024 | 64 | 2
  };
  var flags = flagModes[str];
  if (typeof flags == "undefined") {
    throw new Error(`Unknown file open mode: ${str}`)
  }
  return flags
};
var FS_getMode = (canRead, canWrite) => {
  var mode = 0;
  if (canRead) mode |= 292 | 73;
  if (canWrite) mode |= 146;
  return mode
};
var FS = {
  root: null,
  mounts: [],
  devices: {},
  streams: [],
  nextInode: 1,
  nameTable: null,
  currentPath: "/",
  initialized: false,
  ignorePermissions: true,
  ErrnoError: null,
  genericErrors: {},
  filesystems: null,
  syncFSRequests: 0,
  lookupPath(path, opts = {}) {
    path = PATH_FS.resolve(path);
    if (!path) return {
      path: "",
      node: null
    };
    var defaults = {
      follow_mount: true,
      recurse_count: 0
    };
    opts = Object.assign(defaults, opts);
    if (opts.recurse_count > 8) {
      throw new FS.ErrnoError(32)
    }
    var parts = path.split("/").filter(p => !!p);
    var current = FS.root;
    var current_path = "/";
    for (var i = 0; i < parts.length; i++) {
      var islast = i === parts.length - 1;
      if (islast && opts.parent) {
        break
      }
      current = FS.lookupNode(current, parts[i]);
      current_path = PATH.join2(current_path, parts[i]);
      if (FS.isMountpoint(current)) {
        if (!islast || islast && opts.follow_mount) {
          current = current.mounted.root
        }
      }
      if (!islast || opts.follow) {
        var count = 0;
        while (FS.isLink(current.mode)) {
          var link = FS.readlink(current_path);
          current_path = PATH_FS.resolve(PATH.dirname(current_path), link);
          var lookup = FS.lookupPath(current_path, {
            recurse_count: opts.recurse_count + 1
          });
          current = lookup.node;
          if (count++ > 40) {
            throw new FS.ErrnoError(32)
          }
        }
      }
    }
    return {
      path: current_path,
      node: current
    }
  },
  getPath(node) {
    var path;
    while (true) {
      if (FS.isRoot(node)) {
        var mount = node.mount.mountpoint;
        if (!path) return mount;
        return mount[mount.length - 1] !== "/" ? `${mount}/${path}` : mount + path
      }
      path = path ? `${node.name}/${path}` : node.name;
      node = node.parent
    }
  },
  hashName(parentid, name) {
    var hash = 0;
    for (var i = 0; i < name.length; i++) {
      hash = (hash << 5) - hash + name.charCodeAt(i) | 0
    }
    return (parentid + hash >>> 0) % FS.nameTable.length
  },
  hashAddNode(node) {
    var hash = FS.hashName(node.parent.id, node.name);
    node.name_next = FS.nameTable[hash];
    FS.nameTable[hash] = node
  },
  hashRemoveNode(node) {
    var hash = FS.hashName(node.parent.id, node.name);
    if (FS.nameTable[hash] === node) {
      FS.nameTable[hash] = node.name_next
    } else {
      var current = FS.nameTable[hash];
      while (current) {
        if (current.name_next === node) {
          current.name_next = node.name_next;
          break
        }
        current = current.name_next
      }
    }
  },
  lookupNode(parent, name) {
    var errCode = FS.mayLookup(parent);
    if (errCode) {
      throw new FS.ErrnoError(errCode, parent)
    }
    var hash = FS.hashName(parent.id, name);
    for (var node = FS.nameTable[hash]; node; node = node.name_next) {
      var nodeName = node.name;
      if (node.parent.id === parent.id && nodeName === name) {
        return node
      }
    }
    return FS.lookup(parent, name)
  },
  createNode(parent, name, mode, rdev) {
    var node = new FS.FSNode(parent, name, mode, rdev);
    FS.hashAddNode(node);
    return node
  },
  destroyNode(node) {
    FS.hashRemoveNode(node)
  },
  isRoot(node) {
    return node === node.parent
  },
  isMountpoint(node) {
    return !!node.mounted
  },
  isFile(mode) {
    return (mode & 61440) === 32768
  },
  isDir(mode) {
    return (mode & 61440) === 16384
  },
  isLink(mode) {
    return (mode & 61440) === 40960
  },
  isChrdev(mode) {
    return (mode & 61440) === 8192
  },
  isBlkdev(mode) {
    return (mode & 61440) === 24576
  },
  isFIFO(mode) {
    return (mode & 61440) === 4096
  },
  isSocket(mode) {
    return (mode & 49152) === 49152
  },
  flagsToPermissionString(flag) {
    var perms = ["r", "w", "rw"][flag & 3];
    if (flag & 512) {
      perms += "w"
    }
    return perms
  },
  nodePermissions(node, perms) {
    if (FS.ignorePermissions) {
      return 0
    }
    if (perms.includes("r") && !(node.mode & 292)) {
      return 2
    } else if (perms.includes("w") && !(node.mode & 146)) {
      return 2
    } else if (perms.includes("x") && !(node.mode & 73)) {
      return 2
    }
    return 0
  },
  mayLookup(dir) {
    var errCode = FS.nodePermissions(dir, "x");
    if (errCode) return errCode;
    if (!dir.node_ops.lookup) return 2;
    return 0
  },
  mayCreate(dir, name) {
    try {
      var node = FS.lookupNode(dir, name);
      return 20
    } catch (e) {}
    return FS.nodePermissions(dir, "wx")
  },
  mayDelete(dir, name, isdir) {
    var node;
    try {
      node = FS.lookupNode(dir, name)
    } catch (e) {
      return e.errno
    }
    var errCode = FS.nodePermissions(dir, "wx");
    if (errCode) {
      return errCode
    }
    if (isdir) {
      if (!FS.isDir(node.mode)) {
        return 54
      }
      if (FS.isRoot(node) || FS.getPath(node) === FS.cwd()) {
        return 10
      }
    } else {
      if (FS.isDir(node.mode)) {
        return 31
      }
    }
    return 0
  },
  mayOpen(node, flags) {
    if (!node) {
      return 44
    }
    if (FS.isLink(node.mode)) {
      return 32
    } else if (FS.isDir(node.mode)) {
      if (FS.flagsToPermissionString(flags) !== "r" || flags & 512) {
        return 31
      }
    }
    return FS.nodePermissions(node, FS.flagsToPermissionString(flags))
  },
  MAX_OPEN_FDS: 4096,
  nextfd() {
    for (var fd = 0; fd <= FS.MAX_OPEN_FDS; fd++) {
      if (!FS.streams[fd]) {
        return fd
      }
    }
    throw new FS.ErrnoError(33)
  },
  getStreamChecked(fd) {
    var stream = FS.getStream(fd);
    if (!stream) {
      throw new FS.ErrnoError(8)
    }
    return stream
  },
  getStream: fd => FS.streams[fd],
  createStream(stream, fd = -1) {
    if (!FS.FSStream) {
      FS.FSStream = function () {
        this.shared = {}
      };
      FS.FSStream.prototype = {};
      Object.defineProperties(FS.FSStream.prototype, {
        object: {
          get() {
            return this.node
          },
          set(val) {
            this.node = val
          }
        },
        isRead: {
          get() {
            return (this.flags & 2097155) !== 1
          }
        },
        isWrite: {
          get() {
            return (this.flags & 2097155) !== 0
          }
        },
        isAppend: {
          get() {
            return this.flags & 1024
          }
        },
        flags: {
          get() {
            return this.shared.flags
          },
          set(val) {
            this.shared.flags = val
          }
        },
        position: {
          get() {
            return this.shared.position
          },
          set(val) {
            this.shared.position = val
          }
        }
      })
    }
    stream = Object.assign(new FS.FSStream, stream);
    if (fd == -1) {
      fd = FS.nextfd()
    }
    stream.fd = fd;
    FS.streams[fd] = stream;
    return stream
  },
  closeStream(fd) {
    FS.streams[fd] = null
  },
  chrdev_stream_ops: {
    open(stream) {
      var device = FS.getDevice(stream.node.rdev);
      stream.stream_ops = device.stream_ops;
      if (stream.stream_ops.open) {
        stream.stream_ops.open(stream)
      }
    },
    llseek() {
      throw new FS.ErrnoError(70)
    }
  },
  major: dev => dev >> 8,
  minor: dev => dev & 255,
  makedev: (ma, mi) => ma << 8 | mi,
  registerDevice(dev, ops) {
    FS.devices[dev] = {
      stream_ops: ops
    }
  },
  getDevice: dev => FS.devices[dev],
  getMounts(mount) {
    var mounts = [];
    var check = [mount];
    while (check.length) {
      var m = check.pop();
      mounts.push(m);
      check.push.apply(check, m.mounts)
    }
    return mounts
  },
  syncfs(populate, callback) {
    if (typeof populate == "function") {
      callback = populate;
      populate = false
    }
    FS.syncFSRequests++;
    if (FS.syncFSRequests > 1) {
      err(`warning: ${FS.syncFSRequests} FS.syncfs operations in flight at once, probably just doing extra work`)
    }
    var mounts = FS.getMounts(FS.root.mount);
    var completed = 0;

    function doCallback(errCode) {
      FS.syncFSRequests--;
      return callback(errCode)
    }

    function done(errCode) {
      if (errCode) {
        if (!done.errored) {
          done.errored = true;
          return doCallback(errCode)
        }
        return
      }
      if (++completed >= mounts.length) {
        doCallback(null)
      }
    }
    mounts.forEach(mount => {
      if (!mount.type.syncfs) {
        return done(null)
      }
      mount.type.syncfs(mount, populate, done)
    })
  },
  mount(type, opts, mountpoint) {
    var root = mountpoint === "/";
    var pseudo = !mountpoint;
    var node;
    if (root && FS.root) {
      throw new FS.ErrnoError(10)
    } else if (!root && !pseudo) {
      var lookup = FS.lookupPath(mountpoint, {
        follow_mount: false
      });
      mountpoint = lookup.path;
      node = lookup.node;
      if (FS.isMountpoint(node)) {
        throw new FS.ErrnoError(10)
      }
      if (!FS.isDir(node.mode)) {
        throw new FS.ErrnoError(54)
      }
    }
    var mount = {
      type: type,
      opts: opts,
      mountpoint: mountpoint,
      mounts: []
    };
    var mountRoot = type.mount(mount);
    mountRoot.mount = mount;
    mount.root = mountRoot;
    if (root) {
      FS.root = mountRoot
    } else if (node) {
      node.mounted = mount;
      if (node.mount) {
        node.mount.mounts.push(mount)
      }
    }
    return mountRoot
  },
  unmount(mountpoint) {
    var lookup = FS.lookupPath(mountpoint, {
      follow_mount: false
    });
    if (!FS.isMountpoint(lookup.node)) {
      throw new FS.ErrnoError(28)
    }
    var node = lookup.node;
    var mount = node.mounted;
    var mounts = FS.getMounts(mount);
    Object.keys(FS.nameTable).forEach(hash => {
      var current = FS.nameTable[hash];
      while (current) {
        var next = current.name_next;
        if (mounts.includes(current.mount)) {
          FS.destroyNode(current)
        }
        current = next
      }
    });
    node.mounted = null;
    var idx = node.mount.mounts.indexOf(mount);
    node.mount.mounts.splice(idx, 1)
  },
  lookup(parent, name) {
    return parent.node_ops.lookup(parent, name)
  },
  mknod(path, mode, dev) {
    var lookup = FS.lookupPath(path, {
      parent: true
    });
    var parent = lookup.node;
    var name = PATH.basename(path);
    if (!name || name === "." || name === "..") {
      throw new FS.ErrnoError(28)
    }
    var errCode = FS.mayCreate(parent, name);
    if (errCode) {
      throw new FS.ErrnoError(errCode)
    }
    if (!parent.node_ops.mknod) {
      throw new FS.ErrnoError(63)
    }
    return parent.node_ops.mknod(parent, name, mode, dev)
  },
  create(path, mode) {
    mode = mode !== undefined ? mode : 438;
    mode &= 4095;
    mode |= 32768;
    return FS.mknod(path, mode, 0)
  },
  mkdir(path, mode) {
    mode = mode !== undefined ? mode : 511;
    mode &= 511 | 512;
    mode |= 16384;
    return FS.mknod(path, mode, 0)
  },
  mkdirTree(path, mode) {
    var dirs = path.split("/");
    var d = "";
    for (var i = 0; i < dirs.length; ++i) {
      if (!dirs[i]) continue;
      d += "/" + dirs[i];
      try {
        FS.mkdir(d, mode)
      } catch (e) {
        if (e.errno != 20) throw e
      }
    }
  },
  mkdev(path, mode, dev) {
    if (typeof dev == "undefined") {
      dev = mode;
      mode = 438
    }
    mode |= 8192;
    return FS.mknod(path, mode, dev)
  },
  symlink(oldpath, newpath) {
    if (!PATH_FS.resolve(oldpath)) {
      throw new FS.ErrnoError(44)
    }
    var lookup = FS.lookupPath(newpath, {
      parent: true
    });
    var parent = lookup.node;
    if (!parent) {
      throw new FS.ErrnoError(44)
    }
    var newname = PATH.basename(newpath);
    var errCode = FS.mayCreate(parent, newname);
    if (errCode) {
      throw new FS.ErrnoError(errCode)
    }
    if (!parent.node_ops.symlink) {
      throw new FS.ErrnoError(63)
    }
    return parent.node_ops.symlink(parent, newname, oldpath)
  },
  rename(old_path, new_path) {
    var old_dirname = PATH.dirname(old_path);
    var new_dirname = PATH.dirname(new_path);
    var old_name = PATH.basename(old_path);
    var new_name = PATH.basename(new_path);
    var lookup, old_dir, new_dir;
    lookup = FS.lookupPath(old_path, {
      parent: true
    });
    old_dir = lookup.node;
    lookup = FS.lookupPath(new_path, {
      parent: true
    });
    new_dir = lookup.node;
    if (!old_dir || !new_dir) throw new FS.ErrnoError(44);
    if (old_dir.mount !== new_dir.mount) {
      throw new FS.ErrnoError(75)
    }
    var old_node = FS.lookupNode(old_dir, old_name);
    var relative = PATH_FS.relative(old_path, new_dirname);
    if (relative.charAt(0) !== ".") {
      throw new FS.ErrnoError(28)
    }
    relative = PATH_FS.relative(new_path, old_dirname);
    if (relative.charAt(0) !== ".") {
      throw new FS.ErrnoError(55)
    }
    var new_node;
    try {
      new_node = FS.lookupNode(new_dir, new_name)
    } catch (e) {}
    if (old_node === new_node) {
      return
    }
    var isdir = FS.isDir(old_node.mode);
    var errCode = FS.mayDelete(old_dir, old_name, isdir);
    if (errCode) {
      throw new FS.ErrnoError(errCode)
    }
    errCode = new_node ? FS.mayDelete(new_dir, new_name, isdir) : FS.mayCreate(new_dir, new_name);
    if (errCode) {
      throw new FS.ErrnoError(errCode)
    }
    if (!old_dir.node_ops.rename) {
      throw new FS.ErrnoError(63)
    }
    if (FS.isMountpoint(old_node) || new_node && FS.isMountpoint(new_node)) {
      throw new FS.ErrnoError(10)
    }
    if (new_dir !== old_dir) {
      errCode = FS.nodePermissions(old_dir, "w");
      if (errCode) {
        throw new FS.ErrnoError(errCode)
      }
    }
    FS.hashRemoveNode(old_node);
    try {
      old_dir.node_ops.rename(old_node, new_dir, new_name)
    } catch (e) {
      throw e
    } finally {
      FS.hashAddNode(old_node)
    }
  },
  rmdir(path) {
    var lookup = FS.lookupPath(path, {
      parent: true
    });
    var parent = lookup.node;
    var name = PATH.basename(path);
    var node = FS.lookupNode(parent, name);
    var errCode = FS.mayDelete(parent, name, true);
    if (errCode) {
      throw new FS.ErrnoError(errCode)
    }
    if (!parent.node_ops.rmdir) {
      throw new FS.ErrnoError(63)
    }
    if (FS.isMountpoint(node)) {
      throw new FS.ErrnoError(10)
    }
    parent.node_ops.rmdir(parent, name);
    FS.destroyNode(node)
  },
  readdir(path) {
    var lookup = FS.lookupPath(path, {
      follow: true
    });
    var node = lookup.node;
    if (!node.node_ops.readdir) {
      throw new FS.ErrnoError(54)
    }
    return node.node_ops.readdir(node)
  },
  unlink(path) {
    var lookup = FS.lookupPath(path, {
      parent: true
    });
    var parent = lookup.node;
    if (!parent) {
      throw new FS.ErrnoError(44)
    }
    var name = PATH.basename(path);
    var node = FS.lookupNode(parent, name);
    var errCode = FS.mayDelete(parent, name, false);
    if (errCode) {
      throw new FS.ErrnoError(errCode)
    }
    if (!parent.node_ops.unlink) {
      throw new FS.ErrnoError(63)
    }
    if (FS.isMountpoint(node)) {
      throw new FS.ErrnoError(10)
    }
    parent.node_ops.unlink(parent, name);
    FS.destroyNode(node)
  },
  readlink(path) {
    var lookup = FS.lookupPath(path);
    var link = lookup.node;
    if (!link) {
      throw new FS.ErrnoError(44)
    }
    if (!link.node_ops.readlink) {
      throw new FS.ErrnoError(28)
    }
    return PATH_FS.resolve(FS.getPath(link.parent), link.node_ops.readlink(link))
  },
  stat(path, dontFollow) {
    var lookup = FS.lookupPath(path, {
      follow: !dontFollow
    });
    var node = lookup.node;
    if (!node) {
      throw new FS.ErrnoError(44)
    }
    if (!node.node_ops.getattr) {
      throw new FS.ErrnoError(63)
    }
    return node.node_ops.getattr(node)
  },
  lstat(path) {
    return FS.stat(path, true)
  },
  chmod(path, mode, dontFollow) {
    var node;
    if (typeof path == "string") {
      var lookup = FS.lookupPath(path, {
        follow: !dontFollow
      });
      node = lookup.node
    } else {
      node = path
    }
    if (!node.node_ops.setattr) {
      throw new FS.ErrnoError(63)
    }
    node.node_ops.setattr(node, {
      mode: mode & 4095 | node.mode & ~4095,
      timestamp: Date.now()
    })
  },
  lchmod(path, mode) {
    FS.chmod(path, mode, true)
  },
  fchmod(fd, mode) {
    var stream = FS.getStreamChecked(fd);
    FS.chmod(stream.node, mode)
  },
  chown(path, uid, gid, dontFollow) {
    var node;
    if (typeof path == "string") {
      var lookup = FS.lookupPath(path, {
        follow: !dontFollow
      });
      node = lookup.node
    } else {
      node = path
    }
    if (!node.node_ops.setattr) {
      throw new FS.ErrnoError(63)
    }
    node.node_ops.setattr(node, {
      timestamp: Date.now()
    })
  },
  lchown(path, uid, gid) {
    FS.chown(path, uid, gid, true)
  },
  fchown(fd, uid, gid) {
    var stream = FS.getStreamChecked(fd);
    FS.chown(stream.node, uid, gid)
  },
  truncate(path, len) {
    if (len < 0) {
      throw new FS.ErrnoError(28)
    }
    var node;
    if (typeof path == "string") {
      var lookup = FS.lookupPath(path, {
        follow: true
      });
      node = lookup.node
    } else {
      node = path
    }
    if (!node.node_ops.setattr) {
      throw new FS.ErrnoError(63)
    }
    if (FS.isDir(node.mode)) {
      throw new FS.ErrnoError(31)
    }
    if (!FS.isFile(node.mode)) {
      throw new FS.ErrnoError(28)
    }
    var errCode = FS.nodePermissions(node, "w");
    if (errCode) {
      throw new FS.ErrnoError(errCode)
    }
    node.node_ops.setattr(node, {
      size: len,
      timestamp: Date.now()
    })
  },
  ftruncate(fd, len) {
    var stream = FS.getStreamChecked(fd);
    if ((stream.flags & 2097155) === 0) {
      throw new FS.ErrnoError(28)
    }
    FS.truncate(stream.node, len)
  },
  utime(path, atime, mtime) {
    var lookup = FS.lookupPath(path, {
      follow: true
    });
    var node = lookup.node;
    node.node_ops.setattr(node, {
      timestamp: Math.max(atime, mtime)
    })
  },
  open(path, flags, mode) {
    if (path === "") {
      throw new FS.ErrnoError(44)
    }
    flags = typeof flags == "string" ? FS_modeStringToFlags(flags) : flags;
    mode = typeof mode == "undefined" ? 438 : mode;
    if (flags & 64) {
      mode = mode & 4095 | 32768
    } else {
      mode = 0
    }
    var node;
    if (typeof path == "object") {
      node = path
    } else {
      path = PATH.normalize(path);
      try {
        var lookup = FS.lookupPath(path, {
          follow: !(flags & 131072)
        });
        node = lookup.node
      } catch (e) {}
    }
    var created = false;
    if (flags & 64) {
      if (node) {
        if (flags & 128) {
          throw new FS.ErrnoError(20)
        }
      } else {
        node = FS.mknod(path, mode, 0);
        created = true
      }
    }
    if (!node) {
      throw new FS.ErrnoError(44)
    }
    if (FS.isChrdev(node.mode)) {
      flags &= ~512
    }
    if (flags & 65536 && !FS.isDir(node.mode)) {
      throw new FS.ErrnoError(54)
    }
    if (!created) {
      var errCode = FS.mayOpen(node, flags);
      if (errCode) {
        throw new FS.ErrnoError(errCode)
      }
    }
    if (flags & 512 && !created) {
      FS.truncate(node, 0)
    }
    flags &= ~(128 | 512 | 131072);
    var stream = FS.createStream({
      node: node,
      path: FS.getPath(node),
      flags: flags,
      seekable: true,
      position: 0,
      stream_ops: node.stream_ops,
      ungotten: [],
      error: false
    });
    if (stream.stream_ops.open) {
      stream.stream_ops.open(stream)
    }
    if (Module["logReadFiles"] && !(flags & 1)) {
      if (!FS.readFiles) FS.readFiles = {};
      if (!(path in FS.readFiles)) {
        FS.readFiles[path] = 1
      }
    }
    return stream
  },
  close(stream) {
    if (FS.isClosed(stream)) {
      throw new FS.ErrnoError(8)
    }
    if (stream.getdents) stream.getdents = null;
    try {
      if (stream.stream_ops.close) {
        stream.stream_ops.close(stream)
      }
    } catch (e) {
      throw e
    } finally {
      FS.closeStream(stream.fd)
    }
    stream.fd = null
  },
  isClosed(stream) {
    return stream.fd === null
  },
  llseek(stream, offset, whence) {
    if (FS.isClosed(stream)) {
      throw new FS.ErrnoError(8)
    }
    if (!stream.seekable || !stream.stream_ops.llseek) {
      throw new FS.ErrnoError(70)
    }
    if (whence != 0 && whence != 1 && whence != 2) {
      throw new FS.ErrnoError(28)
    }
    stream.position = stream.stream_ops.llseek(stream, offset, whence);
    stream.ungotten = [];
    return stream.position
  },
  read(stream, buffer, offset, length, position) {
    if (length < 0 || position < 0) {
      throw new FS.ErrnoError(28)
    }
    if (FS.isClosed(stream)) {
      throw new FS.ErrnoError(8)
    }
    if ((stream.flags & 2097155) === 1) {
      throw new FS.ErrnoError(8)
    }
    if (FS.isDir(stream.node.mode)) {
      throw new FS.ErrnoError(31)
    }
    if (!stream.stream_ops.read) {
      throw new FS.ErrnoError(28)
    }
    var seeking = typeof position != "undefined";
    if (!seeking) {
      position = stream.position
    } else if (!stream.seekable) {
      throw new FS.ErrnoError(70)
    }
    var bytesRead = stream.stream_ops.read(stream, buffer, offset, length, position);
    if (!seeking) stream.position += bytesRead;
    return bytesRead
  },
  write(stream, buffer, offset, length, position, canOwn) {
    if (length < 0 || position < 0) {
      throw new FS.ErrnoError(28)
    }
    if (FS.isClosed(stream)) {
      throw new FS.ErrnoError(8)
    }
    if ((stream.flags & 2097155) === 0) {
      throw new FS.ErrnoError(8)
    }
    if (FS.isDir(stream.node.mode)) {
      throw new FS.ErrnoError(31)
    }
    if (!stream.stream_ops.write) {
      throw new FS.ErrnoError(28)
    }
    if (stream.seekable && stream.flags & 1024) {
      FS.llseek(stream, 0, 2)
    }
    var seeking = typeof position != "undefined";
    if (!seeking) {
      position = stream.position
    } else if (!stream.seekable) {
      throw new FS.ErrnoError(70)
    }
    var bytesWritten = stream.stream_ops.write(stream, buffer, offset, length, position, canOwn);
    if (!seeking) stream.position += bytesWritten;
    return bytesWritten
  },
  allocate(stream, offset, length) {
    if (FS.isClosed(stream)) {
      throw new FS.ErrnoError(8)
    }
    if (offset < 0 || length <= 0) {
      throw new FS.ErrnoError(28)
    }
    if ((stream.flags & 2097155) === 0) {
      throw new FS.ErrnoError(8)
    }
    if (!FS.isFile(stream.node.mode) && !FS.isDir(stream.node.mode)) {
      throw new FS.ErrnoError(43)
    }
    if (!stream.stream_ops.allocate) {
      throw new FS.ErrnoError(138)
    }
    stream.stream_ops.allocate(stream, offset, length)
  },
  mmap(stream, length, position, prot, flags) {
    if ((prot & 2) !== 0 && (flags & 2) === 0 && (stream.flags & 2097155) !== 2) {
      throw new FS.ErrnoError(2)
    }
    if ((stream.flags & 2097155) === 1) {
      throw new FS.ErrnoError(2)
    }
    if (!stream.stream_ops.mmap) {
      throw new FS.ErrnoError(43)
    }
    return stream.stream_ops.mmap(stream, length, position, prot, flags)
  },
  msync(stream, buffer, offset, length, mmapFlags) {
    if (!stream.stream_ops.msync) {
      return 0
    }
    return stream.stream_ops.msync(stream, buffer, offset, length, mmapFlags)
  },
  munmap: stream => 0,
  ioctl(stream, cmd, arg) {
    if (!stream.stream_ops.ioctl) {
      throw new FS.ErrnoError(59)
    }
    return stream.stream_ops.ioctl(stream, cmd, arg)
  },
  readFile(path, opts = {}) {
    opts.flags = opts.flags || 0;
    opts.encoding = opts.encoding || "binary";
    if (opts.encoding !== "utf8" && opts.encoding !== "binary") {
      throw new Error(`Invalid encoding type "${opts.encoding}"`)
    }
    var ret;
    var stream = FS.open(path, opts.flags);
    var stat = FS.stat(path);
    var length = stat.size;
    var buf = new Uint8Array(length);
    FS.read(stream, buf, 0, length, 0);
    if (opts.encoding === "utf8") {
      ret = UTF8ArrayToString(buf, 0)
    } else if (opts.encoding === "binary") {
      ret = buf
    }
    FS.close(stream);
    return ret
  },
  writeFile(path, data, opts = {}) {
    opts.flags = opts.flags || 577;
    var stream = FS.open(path, opts.flags, opts.mode);
    if (typeof data == "string") {
      var buf = new Uint8Array(lengthBytesUTF8(data) + 1);
      var actualNumBytes = stringToUTF8Array(data, buf, 0, buf.length);
      FS.write(stream, buf, 0, actualNumBytes, undefined, opts.canOwn)
    } else if (ArrayBuffer.isView(data)) {
      FS.write(stream, data, 0, data.byteLength, undefined, opts.canOwn)
    } else {
      throw new Error("Unsupported data type")
    }
    FS.close(stream)
  },
  cwd: () => FS.currentPath,
  chdir(path) {
    var lookup = FS.lookupPath(path, {
      follow: true
    });
    if (lookup.node === null) {
      throw new FS.ErrnoError(44)
    }
    if (!FS.isDir(lookup.node.mode)) {
      throw new FS.ErrnoError(54)
    }
    var errCode = FS.nodePermissions(lookup.node, "x");
    if (errCode) {
      throw new FS.ErrnoError(errCode)
    }
    FS.currentPath = lookup.path
  },
  createDefaultDirectories() {
    FS.mkdir("/tmp");
    FS.mkdir("/home");
    FS.mkdir("/home/web_user")
  },
  createDefaultDevices() {
    FS.mkdir("/dev");
    FS.registerDevice(FS.makedev(1, 3), {
      read: () => 0,
      write: (stream, buffer, offset, length, pos) => length
    });
    FS.mkdev("/dev/null", FS.makedev(1, 3));
    TTY.register(FS.makedev(5, 0), TTY.default_tty_ops);
    TTY.register(FS.makedev(6, 0), TTY.default_tty1_ops);
    FS.mkdev("/dev/tty", FS.makedev(5, 0));
    FS.mkdev("/dev/tty1", FS.makedev(6, 0));
    var randomBuffer = new Uint8Array(1024),
      randomLeft = 0;
    var randomByte = () => {
      if (randomLeft === 0) {
        randomLeft = randomFill(randomBuffer).byteLength
      }
      return randomBuffer[--randomLeft]
    };
    FS.createDevice("/dev", "random", randomByte);
    FS.createDevice("/dev", "urandom", randomByte);
    FS.mkdir("/dev/shm");
    FS.mkdir("/dev/shm/tmp")
  },
  createSpecialDirectories() {
    FS.mkdir("/proc");
    var proc_self = FS.mkdir("/proc/self");
    FS.mkdir("/proc/self/fd");
    FS.mount({
      mount() {
        var node = FS.createNode(proc_self, "fd", 16384 | 511, 73);
        node.node_ops = {
          lookup(parent, name) {
            var fd = +name;
            var stream = FS.getStreamChecked(fd);
            var ret = {
              parent: null,
              mount: {
                mountpoint: "fake"
              },
              node_ops: {
                readlink: () => stream.path
              }
            };
            ret.parent = ret;
            return ret
          }
        };
        return node
      }
    }, {}, "/proc/self/fd")
  },
  createStandardStreams() {
    if (Module["stdin"]) {
      FS.createDevice("/dev", "stdin", Module["stdin"])
    } else {
      FS.symlink("/dev/tty", "/dev/stdin")
    }
    if (Module["stdout"]) {
      FS.createDevice("/dev", "stdout", null, Module["stdout"])
    } else {
      FS.symlink("/dev/tty", "/dev/stdout")
    }
    if (Module["stderr"]) {
      FS.createDevice("/dev", "stderr", null, Module["stderr"])
    } else {
      FS.symlink("/dev/tty1", "/dev/stderr")
    }
    var stdin = FS.open("/dev/stdin", 0);
    var stdout = FS.open("/dev/stdout", 1);
    var stderr = FS.open("/dev/stderr", 1)
  },
  ensureErrnoError() {
    if (FS.ErrnoError) return;
    FS.ErrnoError = function ErrnoError(errno, node) {
      this.name = "ErrnoError";
      this.node = node;
      this.setErrno = function (errno) {
        this.errno = errno
      };
      this.setErrno(errno);
      this.message = "FS error"
    };
    FS.ErrnoError.prototype = new Error;
    FS.ErrnoError.prototype.constructor = FS.ErrnoError;
    [44].forEach(code => {
      FS.genericErrors[code] = new FS.ErrnoError(code);
      FS.genericErrors[code].stack = "<generic error, no stack>"
    })
  },
  staticInit() {
    FS.ensureErrnoError();
    FS.nameTable = new Array(4096);
    FS.mount(MEMFS, {}, "/");
    FS.createDefaultDirectories();
    FS.createDefaultDevices();
    FS.createSpecialDirectories();
    FS.filesystems = {
      "MEMFS": MEMFS
    }
  },
  init(input, output, error) {
    FS.init.initialized = true;
    FS.ensureErrnoError();
    Module["stdin"] = input || Module["stdin"];
    Module["stdout"] = output || Module["stdout"];
    Module["stderr"] = error || Module["stderr"];
    FS.createStandardStreams()
  },
  quit() {
    FS.init.initialized = false;
    for (var i = 0; i < FS.streams.length; i++) {
      var stream = FS.streams[i];
      if (!stream) {
        continue
      }
      FS.close(stream)
    }
  },
  findObject(path, dontResolveLastLink) {
    var ret = FS.analyzePath(path, dontResolveLastLink);
    if (!ret.exists) {
      return null
    }
    return ret.object
  },
  analyzePath(path, dontResolveLastLink) {
    try {
      var lookup = FS.lookupPath(path, {
        follow: !dontResolveLastLink
      });
      path = lookup.path
    } catch (e) {}
    var ret = {
      isRoot: false,
      exists: false,
      error: 0,
      name: null,
      path: null,
      object: null,
      parentExists: false,
      parentPath: null,
      parentObject: null
    };
    try {
      var lookup = FS.lookupPath(path, {
        parent: true
      });
      ret.parentExists = true;
      ret.parentPath = lookup.path;
      ret.parentObject = lookup.node;
      ret.name = PATH.basename(path);
      lookup = FS.lookupPath(path, {
        follow: !dontResolveLastLink
      });
      ret.exists = true;
      ret.path = lookup.path;
      ret.object = lookup.node;
      ret.name = lookup.node.name;
      ret.isRoot = lookup.path === "/"
    } catch (e) {
      ret.error = e.errno
    }
    return ret
  },
  createPath(parent, path, canRead, canWrite) {
    parent = typeof parent == "string" ? parent : FS.getPath(parent);
    var parts = path.split("/").reverse();
    while (parts.length) {
      var part = parts.pop();
      if (!part) continue;
      var current = PATH.join2(parent, part);
      try {
        FS.mkdir(current)
      } catch (e) {}
      parent = current
    }
    return current
  },
  createFile(parent, name, properties, canRead, canWrite) {
    var path = PATH.join2(typeof parent == "string" ? parent : FS.getPath(parent), name);
    var mode = FS_getMode(canRead, canWrite);
    return FS.create(path, mode)
  },
  createDataFile(parent, name, data, canRead, canWrite, canOwn) {
    var path = name;
    if (parent) {
      parent = typeof parent == "string" ? parent : FS.getPath(parent);
      path = name ? PATH.join2(parent, name) : parent
    }
    var mode = FS_getMode(canRead, canWrite);
    var node = FS.create(path, mode);
    if (data) {
      if (typeof data == "string") {
        var arr = new Array(data.length);
        for (var i = 0, len = data.length; i < len; ++i) arr[i] = data.charCodeAt(i);
        data = arr
      }
      FS.chmod(node, mode | 146);
      var stream = FS.open(node, 577);
      FS.write(stream, data, 0, data.length, 0, canOwn);
      FS.close(stream);
      FS.chmod(node, mode)
    }
    return node
  },
  createDevice(parent, name, input, output) {
    var path = PATH.join2(typeof parent == "string" ? parent : FS.getPath(parent), name);
    var mode = FS_getMode(!!input, !!output);
    if (!FS.createDevice.major) FS.createDevice.major = 64;
    var dev = FS.makedev(FS.createDevice.major++, 0);
    FS.registerDevice(dev, {
      open(stream) {
        stream.seekable = false
      },
      close(stream) {
        if (output && output.buffer && output.buffer.length) {
          output(10)
        }
      },
      read(stream, buffer, offset, length, pos) {
        var bytesRead = 0;
        for (var i = 0; i < length; i++) {
          var result;
          try {
            result = input()
          } catch (e) {
            throw new FS.ErrnoError(29)
          }
          if (result === undefined && bytesRead === 0) {
            throw new FS.ErrnoError(6)
          }
          if (result === null || result === undefined) break;
          bytesRead++;
          buffer[offset + i] = result
        }
        if (bytesRead) {
          stream.node.timestamp = Date.now()
        }
        return bytesRead
      },
      write(stream, buffer, offset, length, pos) {
        for (var i = 0; i < length; i++) {
          try {
            output(buffer[offset + i])
          } catch (e) {
            throw new FS.ErrnoError(29)
          }
        }
        if (length) {
          stream.node.timestamp = Date.now()
        }
        return i
      }
    });
    return FS.mkdev(path, mode, dev)
  },
  forceLoadFile(obj) {
    if (obj.isDevice || obj.isFolder || obj.link || obj.contents) return true;
    if (typeof XMLHttpRequest != "undefined") {
      throw new Error("Lazy loading should have been performed (contents set) in createLazyFile, but it was not. Lazy loading only works in web workers. Use --embed-file or --preload-file in emcc on the main thread.")
    } else if (read_) {
      try {
        obj.contents = intArrayFromString(read_(obj.url), true);
        obj.usedBytes = obj.contents.length
      } catch (e) {
        throw new FS.ErrnoError(29)
      }
    } else {
      throw new Error("Cannot load without read() or XMLHttpRequest.")
    }
  },
  createLazyFile(parent, name, url, canRead, canWrite) {
    function LazyUint8Array() {
      this.lengthKnown = false;
      this.chunks = []
    }
    LazyUint8Array.prototype.get = function LazyUint8Array_get(idx) {
      if (idx > this.length - 1 || idx < 0) {
        return undefined
      }
      var chunkOffset = idx % this.chunkSize;
      var chunkNum = idx / this.chunkSize | 0;
      return this.getter(chunkNum)[chunkOffset]
    };
    LazyUint8Array.prototype.setDataGetter = function LazyUint8Array_setDataGetter(getter) {
      this.getter = getter
    };
    LazyUint8Array.prototype.cacheLength = function LazyUint8Array_cacheLength() {
      var xhr = new XMLHttpRequest;
      xhr.open("HEAD", url, false);
      xhr.send(null);
      if (!(xhr.status >= 200 && xhr.status < 300 || xhr.status === 304)) throw new Error("Couldn't load " + url + ". Status: " + xhr.status);
      var datalength = Number(xhr.getResponseHeader("Content-length"));
      var header;
      var hasByteServing = (header = xhr.getResponseHeader("Accept-Ranges")) && header === "bytes";
      var usesGzip = (header = xhr.getResponseHeader("Content-Encoding")) && header === "gzip";
      var chunkSize = 1024 * 1024;
      if (!hasByteServing) chunkSize = datalength;
      var doXHR = (from, to) => {
        if (from > to) throw new Error("invalid range (" + from + ", " + to + ") or no bytes requested!");
        if (to > datalength - 1) throw new Error("only " + datalength + " bytes available! programmer error!");
        var xhr = new XMLHttpRequest;
        xhr.open("GET", url, false);
        if (datalength !== chunkSize) xhr.setRequestHeader("Range", "bytes=" + from + "-" + to);
        xhr.responseType = "arraybuffer";
        if (xhr.overrideMimeType) {
          xhr.overrideMimeType("text/plain; charset=x-user-defined")
        }
        xhr.send(null);
        if (!(xhr.status >= 200 && xhr.status < 300 || xhr.status === 304)) throw new Error("Couldn't load " + url + ". Status: " + xhr.status);
        if (xhr.response !== undefined) {
          return new Uint8Array(xhr.response || [])
        }
        return intArrayFromString(xhr.responseText || "", true)
      };
      var lazyArray = this;
      lazyArray.setDataGetter(chunkNum => {
        var start = chunkNum * chunkSize;
        var end = (chunkNum + 1) * chunkSize - 1;
        end = Math.min(end, datalength - 1);
        if (typeof lazyArray.chunks[chunkNum] == "undefined") {
          lazyArray.chunks[chunkNum] = doXHR(start, end)
        }
        if (typeof lazyArray.chunks[chunkNum] == "undefined") throw new Error("doXHR failed!");
        return lazyArray.chunks[chunkNum]
      });
      if (usesGzip || !datalength) {
        chunkSize = datalength = 1;
        datalength = this.getter(0).length;
        chunkSize = datalength;
        out("LazyFiles on gzip forces download of the whole file when length is accessed")
      }
      this._length = datalength;
      this._chunkSize = chunkSize;
      this.lengthKnown = true
    };
    if (typeof XMLHttpRequest != "undefined") {
      if (!ENVIRONMENT_IS_WORKER) throw "Cannot do synchronous binary XHRs outside webworkers in modern browsers. Use --embed-file or --preload-file in emcc";
      var lazyArray = new LazyUint8Array;
      Object.defineProperties(lazyArray, {
        length: {
          get: function () {
            if (!this.lengthKnown) {
              this.cacheLength()
            }
            return this._length
          }
        },
        chunkSize: {
          get: function () {
            if (!this.lengthKnown) {
              this.cacheLength()
            }
            return this._chunkSize
          }
        }
      });
      var properties = {
        isDevice: false,
        contents: lazyArray
      }
    } else {
      var properties = {
        isDevice: false,
        url: url
      }
    }
    var node = FS.createFile(parent, name, properties, canRead, canWrite);
    if (properties.contents) {
      node.contents = properties.contents
    } else if (properties.url) {
      node.contents = null;
      node.url = properties.url
    }
    Object.defineProperties(node, {
      usedBytes: {
        get: function () {
          return this.contents.length
        }
      }
    });
    var stream_ops = {};
    var keys = Object.keys(node.stream_ops);
    keys.forEach(key => {
      var fn = node.stream_ops[key];
      stream_ops[key] = function forceLoadLazyFile() {
        FS.forceLoadFile(node);
        return fn.apply(null, arguments)
      }
    });

    function writeChunks(stream, buffer, offset, length, position) {
      var contents = stream.node.contents;
      if (position >= contents.length) return 0;
      var size = Math.min(contents.length - position, length);
      if (contents.slice) {
        for (var i = 0; i < size; i++) {
          buffer[offset + i] = contents[position + i]
        }
      } else {
        for (var i = 0; i < size; i++) {
          buffer[offset + i] = contents.get(position + i)
        }
      }
      return size
    }
    stream_ops.read = (stream, buffer, offset, length, position) => {
      FS.forceLoadFile(node);
      return writeChunks(stream, buffer, offset, length, position)
    };
    stream_ops.mmap = (stream, length, position, prot, flags) => {
      FS.forceLoadFile(node);
      var ptr = mmapAlloc(length);
      if (!ptr) {
        throw new FS.ErrnoError(48)
      }
      writeChunks(stream, GROWABLE_HEAP_I8(), ptr, length, position);
      return {
        ptr: ptr,
        allocated: true
      }
    };
    node.stream_ops = stream_ops;
    return node
  }
};
var UTF8ToString = (ptr, maxBytesToRead) => ptr ? UTF8ArrayToString(GROWABLE_HEAP_U8(), ptr, maxBytesToRead) : "";
var SYSCALLS = {
  DEFAULT_POLLMASK: 5,
  calculateAt(dirfd, path, allowEmpty) {
    if (PATH.isAbs(path)) {
      return path
    }
    var dir;
    if (dirfd === -100) {
      dir = FS.cwd()
    } else {
      var dirstream = SYSCALLS.getStreamFromFD(dirfd);
      dir = dirstream.path
    }
    if (path.length == 0) {
      if (!allowEmpty) {
        throw new FS.ErrnoError(44)
      }
      return dir
    }
    return PATH.join2(dir, path)
  },
  doStat(func, path, buf) {
    try {
      var stat = func(path)
    } catch (e) {
      if (e && e.node && PATH.normalize(path) !== PATH.normalize(FS.getPath(e.node))) {
        return -54
      }
      throw e
    }
    GROWABLE_HEAP_I32()[buf >> 2] = stat.dev;
    GROWABLE_HEAP_I32()[buf + 4 >> 2] = stat.mode;
    GROWABLE_HEAP_U32()[buf + 8 >> 2] = stat.nlink;
    GROWABLE_HEAP_I32()[buf + 12 >> 2] = stat.uid;
    GROWABLE_HEAP_I32()[buf + 16 >> 2] = stat.gid;
    GROWABLE_HEAP_I32()[buf + 20 >> 2] = stat.rdev;
    tempI64 = [stat.size >>> 0, (tempDouble = stat.size, +Math.abs(tempDouble) >= 1 ? tempDouble > 0 ? +Math.floor(tempDouble / 4294967296) >>> 0 : ~~+Math.ceil((tempDouble - +(~~tempDouble >>> 0)) / 4294967296) >>> 0 : 0)], GROWABLE_HEAP_I32()[buf + 24 >> 2] = tempI64[0], GROWABLE_HEAP_I32()[buf + 28 >> 2] = tempI64[1];
    GROWABLE_HEAP_I32()[buf + 32 >> 2] = 4096;
    GROWABLE_HEAP_I32()[buf + 36 >> 2] = stat.blocks;
    var atime = stat.atime.getTime();
    var mtime = stat.mtime.getTime();
    var ctime = stat.ctime.getTime();
    tempI64 = [Math.floor(atime / 1e3) >>> 0, (tempDouble = Math.floor(atime / 1e3), +Math.abs(tempDouble) >= 1 ? tempDouble > 0 ? +Math.floor(tempDouble / 4294967296) >>> 0 : ~~+Math.ceil((tempDouble - +(~~tempDouble >>> 0)) / 4294967296) >>> 0 : 0)], GROWABLE_HEAP_I32()[buf + 40 >> 2] = tempI64[0], GROWABLE_HEAP_I32()[buf + 44 >> 2] = tempI64[1];
    GROWABLE_HEAP_U32()[buf + 48 >> 2] = atime % 1e3 * 1e3;
    tempI64 = [Math.floor(mtime / 1e3) >>> 0, (tempDouble = Math.floor(mtime / 1e3), +Math.abs(tempDouble) >= 1 ? tempDouble > 0 ? +Math.floor(tempDouble / 4294967296) >>> 0 : ~~+Math.ceil((tempDouble - +(~~tempDouble >>> 0)) / 4294967296) >>> 0 : 0)], GROWABLE_HEAP_I32()[buf + 56 >> 2] = tempI64[0], GROWABLE_HEAP_I32()[buf + 60 >> 2] = tempI64[1];
    GROWABLE_HEAP_U32()[buf + 64 >> 2] = mtime % 1e3 * 1e3;
    tempI64 = [Math.floor(ctime / 1e3) >>> 0, (tempDouble = Math.floor(ctime / 1e3), +Math.abs(tempDouble) >= 1 ? tempDouble > 0 ? +Math.floor(tempDouble / 4294967296) >>> 0 : ~~+Math.ceil((tempDouble - +(~~tempDouble >>> 0)) / 4294967296) >>> 0 : 0)], GROWABLE_HEAP_I32()[buf + 72 >> 2] = tempI64[0], GROWABLE_HEAP_I32()[buf + 76 >> 2] = tempI64[1];
    GROWABLE_HEAP_U32()[buf + 80 >> 2] = ctime % 1e3 * 1e3;
    tempI64 = [stat.ino >>> 0, (tempDouble = stat.ino, +Math.abs(tempDouble) >= 1 ? tempDouble > 0 ? +Math.floor(tempDouble / 4294967296) >>> 0 : ~~+Math.ceil((tempDouble - +(~~tempDouble >>> 0)) / 4294967296) >>> 0 : 0)], GROWABLE_HEAP_I32()[buf + 88 >> 2] = tempI64[0], GROWABLE_HEAP_I32()[buf + 92 >> 2] = tempI64[1];
    return 0
  },
  doMsync(addr, stream, len, flags, offset) {
    if (!FS.isFile(stream.node.mode)) {
      throw new FS.ErrnoError(43)
    }
    if (flags & 2) {
      return 0
    }
    var buffer = GROWABLE_HEAP_U8().slice(addr, addr + len);
    FS.msync(stream, buffer, offset, len, flags)
  },
  varargs: undefined,
  get() {
    var ret = GROWABLE_HEAP_I32()[+SYSCALLS.varargs >> 2];
    SYSCALLS.varargs += 4;
    return ret
  },
  getp() {
    return SYSCALLS.get()
  },
  getStr(ptr) {
    var ret = UTF8ToString(ptr);
    return ret
  },
  getStreamFromFD(fd) {
    var stream = FS.getStreamChecked(fd);
    return stream
  }
};

function _proc_exit(code) {
  if (ENVIRONMENT_IS_PTHREAD) return proxyToMainThread(0, 1, code);
  EXITSTATUS = code;
  if (!keepRuntimeAlive()) {
    PThread.terminateAllThreads();
    if (Module["onExit"]) Module["onExit"](code);
    ABORT = true
  }
  quit_(code, new ExitStatus(code))
}
var exitJS = (status, implicit) => {
  EXITSTATUS = status;
  if (ENVIRONMENT_IS_PTHREAD) {
    exitOnMainThread(status);
    throw "unwind"
  }
  _proc_exit(status)
};
var _exit = exitJS;
var handleException = e => {
  if (e instanceof ExitStatus || e == "unwind") {
    return EXITSTATUS
  }
  quit_(1, e)
};
var PThread = {
  unusedWorkers: [],
  runningWorkers: [],
  tlsInitFunctions: [],
  pthreads: {},
  init() {
    if (ENVIRONMENT_IS_PTHREAD) {
      PThread.initWorker()
    } else {
      PThread.initMainThread()
    }
  },
  initMainThread() {
    addOnPreRun(() => {
      addRunDependency("loading-workers");
      PThread.loadWasmModuleToAllWorkers(() => removeRunDependency("loading-workers"))
    })
  },
  initWorker() {
    noExitRuntime = false
  },
  setExitStatus: status => {
    EXITSTATUS = status
  },
  terminateAllThreads__deps: ["$terminateWorker"],
  terminateAllThreads: () => {
    for (var worker of PThread.runningWorkers) {
      terminateWorker(worker)
    }
    for (var worker of PThread.unusedWorkers) {
      terminateWorker(worker)
    }
    PThread.unusedWorkers = [];
    PThread.runningWorkers = [];
    PThread.pthreads = []
  },
  returnWorkerToPool: worker => {
    var pthread_ptr = worker.pthread_ptr;
    delete PThread.pthreads[pthread_ptr];
    PThread.unusedWorkers.push(worker);
    PThread.runningWorkers.splice(PThread.runningWorkers.indexOf(worker), 1);
    worker.pthread_ptr = 0;
    __emscripten_thread_free_data(pthread_ptr)
  },
  receiveObjectTransfer(data) {},
  threadInitTLS() {
    PThread.tlsInitFunctions.forEach(f => f())
  },
  loadWasmModuleToWorker: worker => new Promise(onFinishedLoading => {
    worker.onmessage = e => {
      var d = e["data"];
      var cmd = d["cmd"];
      if (d["targetThread"] && d["targetThread"] != _pthread_self()) {
        var targetWorker = PThread.pthreads[d["targetThread"]];
        if (targetWorker) {
          targetWorker.postMessage(d, d["transferList"])
        } else {
          err(`Internal error! Worker sent a message "${cmd}" to target pthread ${d["targetThread"]}, but that thread no longer exists!`)
        }
        return
      }
      if (cmd === "checkMailbox") {
        checkMailbox()
      } else if (cmd === "spawnThread") {
        spawnThread(d)
      } else if (cmd === "cleanupThread") {
        cleanupThread(d["thread"])
      } else if (cmd === "killThread") {
        killThread(d["thread"])
      } else if (cmd === "cancelThread") {
        cancelThread(d["thread"])
      } else if (cmd === "loaded") {
        worker.loaded = true;
        onFinishedLoading(worker)
      } else if (cmd === "alert") {
        alert(`Thread ${d["threadId"]}: ${d["text"]}`)
      } else if (d.target === "setimmediate") {
        worker.postMessage(d)
      } else if (cmd === "callHandler") {
        Module[d["handler"]](...d["args"])
      } else if (cmd) {
        err(`worker sent an unknown command ${cmd}`)
      }
    };
    worker.onerror = e => {
      var message = "worker sent an error!";
      err(`${message} ${e.filename}:${e.lineno}: ${e.message}`);
      throw e
    };
    if (ENVIRONMENT_IS_NODE) {
      worker.on("message", data => worker.onmessage({
        data: data
      }));
      worker.on("error", e => worker.onerror(e))
    }
    var handlers = [];
    var knownHandlers = ["onExit", "onAbort", "print", "printErr"];
    for (var handler of knownHandlers) {
      if (Module.hasOwnProperty(handler)) {
        handlers.push(handler)
      }
    }
    worker.postMessage({
      "cmd": "load",
      "handlers": handlers,
      "urlOrBlob": Module["mainScriptUrlOrBlob"] || _scriptDir,
      "wasmMemory": wasmMemory,
      "wasmModule": wasmModule
    })
  }),
  loadWasmModuleToAllWorkers(onMaybeReady) {
    onMaybeReady()
  },
  allocateUnusedWorker() {
    var worker;
    var pthreadMainJs = locateFile("RenderCoreEngine.worker.js");
    worker = new Worker(pthreadMainJs);
    PThread.unusedWorkers.push(worker)
  },
  getNewWorker() {
    if (PThread.unusedWorkers.length == 0) {
      PThread.allocateUnusedWorker();
      PThread.loadWasmModuleToWorker(PThread.unusedWorkers[0])
    }
    return PThread.unusedWorkers.pop()
  }
};
Module["PThread"] = PThread;
var callRuntimeCallbacks = callbacks => {
  while (callbacks.length > 0) {
    callbacks.shift()(Module)
  }
};
var establishStackSpace = () => {
  var pthread_ptr = _pthread_self();
  var stackHigh = GROWABLE_HEAP_U32()[pthread_ptr + 52 >> 2];
  var stackSize = GROWABLE_HEAP_U32()[pthread_ptr + 56 >> 2];
  var stackLow = stackHigh - stackSize;
  _emscripten_stack_set_limits(stackHigh, stackLow);
  stackRestore(stackHigh)
};
Module["establishStackSpace"] = establishStackSpace;

function exitOnMainThread(returnCode) {
  if (ENVIRONMENT_IS_PTHREAD) return proxyToMainThread(1, 0, returnCode);
  _exit(returnCode)
}
var wasmTableMirror = [];
var wasmTable;
var getWasmTableEntry = funcPtr => {
  var func = wasmTableMirror[funcPtr];
  if (!func) {
    if (funcPtr >= wasmTableMirror.length) wasmTableMirror.length = funcPtr + 1;
    wasmTableMirror[funcPtr] = func = wasmTable.get(funcPtr)
  }
  return func
};
var invokeEntryPoint = (ptr, arg) => {
  var result = getWasmTableEntry(ptr)(arg);

  function finish(result) {
    if (keepRuntimeAlive()) {
      PThread.setExitStatus(result)
    } else {
      __emscripten_thread_exit(result)
    }
  }
  finish(result)
};
Module["invokeEntryPoint"] = invokeEntryPoint;
var noExitRuntime = Module["noExitRuntime"] || true;
var registerTLSInit = tlsInitFunc => {
  PThread.tlsInitFunctions.push(tlsInitFunc)
};

function ExceptionInfo(excPtr) {
  this.excPtr = excPtr;
  this.ptr = excPtr - 24;
  this.set_type = function (type) {
    GROWABLE_HEAP_U32()[this.ptr + 4 >> 2] = type
  };
  this.get_type = function () {
    return GROWABLE_HEAP_U32()[this.ptr + 4 >> 2]
  };
  this.set_destructor = function (destructor) {
    GROWABLE_HEAP_U32()[this.ptr + 8 >> 2] = destructor
  };
  this.get_destructor = function () {
    return GROWABLE_HEAP_U32()[this.ptr + 8 >> 2]
  };
  this.set_caught = function (caught) {
    caught = caught ? 1 : 0;
    GROWABLE_HEAP_I8()[this.ptr + 12 >> 0] = caught
  };
  this.get_caught = function () {
    return GROWABLE_HEAP_I8()[this.ptr + 12 >> 0] != 0
  };
  this.set_rethrown = function (rethrown) {
    rethrown = rethrown ? 1 : 0;
    GROWABLE_HEAP_I8()[this.ptr + 13 >> 0] = rethrown
  };
  this.get_rethrown = function () {
    return GROWABLE_HEAP_I8()[this.ptr + 13 >> 0] != 0
  };
  this.init = function (type, destructor) {
    this.set_adjusted_ptr(0);
    this.set_type(type);
    this.set_destructor(destructor)
  };
  this.set_adjusted_ptr = function (adjustedPtr) {
    GROWABLE_HEAP_U32()[this.ptr + 16 >> 2] = adjustedPtr
  };
  this.get_adjusted_ptr = function () {
    return GROWABLE_HEAP_U32()[this.ptr + 16 >> 2]
  };
  this.get_exception_ptr = function () {
    var isPointer = ___cxa_is_pointer_type(this.get_type());
    if (isPointer) {
      return GROWABLE_HEAP_U32()[this.excPtr >> 2]
    }
    var adjusted = this.get_adjusted_ptr();
    if (adjusted !== 0) return adjusted;
    return this.excPtr
  }
}
var exceptionLast = 0;
var uncaughtExceptionCount = 0;
var ___cxa_throw = (ptr, type, destructor) => {
  var info = new ExceptionInfo(ptr);
  info.init(type, destructor);
  exceptionLast = ptr;
  uncaughtExceptionCount++;
  throw exceptionLast
};
var ___emscripten_init_main_thread_js = tb => {
  __emscripten_thread_init(tb, !ENVIRONMENT_IS_WORKER, 1, !ENVIRONMENT_IS_WEB, 5242880, false);
  PThread.threadInitTLS()
};
var ___emscripten_thread_cleanup = thread => {
  if (!ENVIRONMENT_IS_PTHREAD) cleanupThread(thread);
  else postMessage({
    "cmd": "cleanupThread",
    "thread": thread
  })
};
var __embind_register_bigint = (primitiveType, name, size, minRange, maxRange) => {};
var embind_init_charCodes = () => {
  var codes = new Array(256);
  for (var i = 0; i < 256; ++i) {
    codes[i] = String.fromCharCode(i)
  }
  embind_charCodes = codes
};
var embind_charCodes;
var readLatin1String = ptr => {
  var ret = "";
  var c = ptr;
  while (GROWABLE_HEAP_U8()[c]) {
    ret += embind_charCodes[GROWABLE_HEAP_U8()[c++]]
  }
  return ret
};
var awaitingDependencies = {};
var registeredTypes = {};
var typeDependencies = {};
var BindingError;
var throwBindingError = message => {
  throw new BindingError(message)
};
var InternalError;

function sharedRegisterType(rawType, registeredInstance, options = {}) {
  var name = registeredInstance.name;
  if (!rawType) {
    throwBindingError(`type "${name}" must have a positive integer typeid pointer`)
  }
  if (registeredTypes.hasOwnProperty(rawType)) {
    if (options.ignoreDuplicateRegistrations) {
      return
    } else {
      throwBindingError(`Cannot register type '${name}' twice`)
    }
  }
  registeredTypes[rawType] = registeredInstance;
  delete typeDependencies[rawType];
  if (awaitingDependencies.hasOwnProperty(rawType)) {
    var callbacks = awaitingDependencies[rawType];
    delete awaitingDependencies[rawType];
    callbacks.forEach(cb => cb())
  }
}

function registerType(rawType, registeredInstance, options = {}) {
  if (!("argPackAdvance" in registeredInstance)) {
    throw new TypeError("registerType registeredInstance requires argPackAdvance")
  }
  return sharedRegisterType(rawType, registeredInstance, options)
}
var GenericWireTypeSize = 8;
var __embind_register_bool = (rawType, name, trueValue, falseValue) => {
  name = readLatin1String(name);
  registerType(rawType, {
    name: name,
    "fromWireType": function (wt) {
      return !!wt
    },
    "toWireType": function (destructors, o) {
      return o ? trueValue : falseValue
    },
    "argPackAdvance": GenericWireTypeSize,
    "readValueFromPointer": function (pointer) {
      return this["fromWireType"](GROWABLE_HEAP_U8()[pointer])
    },
    destructorFunction: null
  })
};

function handleAllocatorInit() {
  Object.assign(HandleAllocator.prototype, {
    get(id) {
      return this.allocated[id]
    },
    has(id) {
      return this.allocated[id] !== undefined
    },
    allocate(handle) {
      var id = this.freelist.pop() || this.allocated.length;
      this.allocated[id] = handle;
      return id
    },
    free(id) {
      this.allocated[id] = undefined;
      this.freelist.push(id)
    }
  })
}

function HandleAllocator() {
  this.allocated = [undefined];
  this.freelist = []
}
var emval_handles = new HandleAllocator;
var __emval_decref = handle => {
  if (handle >= emval_handles.reserved && 0 === --emval_handles.get(handle).refcount) {
    emval_handles.free(handle)
  }
};
var count_emval_handles = () => {
  var count = 0;
  for (var i = emval_handles.reserved; i < emval_handles.allocated.length; ++i) {
    if (emval_handles.allocated[i] !== undefined) {
      ++count
    }
  }
  return count
};
var init_emval = () => {
  emval_handles.allocated.push({
    value: undefined
  }, {
    value: null
  }, {
    value: true
  }, {
    value: false
  });
  emval_handles.reserved = emval_handles.allocated.length;
  Module["count_emval_handles"] = count_emval_handles
};
var Emval = {
  toValue: handle => {
    if (!handle) {
      throwBindingError("Cannot use deleted val. handle = " + handle)
    }
    return emval_handles.get(handle).value
  },
  toHandle: value => {
    switch (value) {
      case undefined:
        return 1;
      case null:
        return 2;
      case true:
        return 3;
      case false:
        return 4;
      default: {
        return emval_handles.allocate({
          refcount: 1,
          value: value
        })
      }
    }
  }
};

function simpleReadValueFromPointer(pointer) {
  return this["fromWireType"](GROWABLE_HEAP_I32()[pointer >> 2])
}
var __embind_register_emval = (rawType, name) => {
  name = readLatin1String(name);
  registerType(rawType, {
    name: name,
    "fromWireType": handle => {
      var rv = Emval.toValue(handle);
      __emval_decref(handle);
      return rv
    },
    "toWireType": (destructors, value) => Emval.toHandle(value),
    "argPackAdvance": GenericWireTypeSize,
    "readValueFromPointer": simpleReadValueFromPointer,
    destructorFunction: null
  })
};
var floatReadValueFromPointer = (name, width) => {
  switch (width) {
    case 4:
      return function (pointer) {
        return this["fromWireType"](GROWABLE_HEAP_F32()[pointer >> 2])
      };
    case 8:
      return function (pointer) {
        return this["fromWireType"](GROWABLE_HEAP_F64()[pointer >> 3])
      };
    default:
      throw new TypeError(`invalid float width (${width}): ${name}`)
  }
};
var __embind_register_float = (rawType, name, size) => {
  name = readLatin1String(name);
  registerType(rawType, {
    name: name,
    "fromWireType": value => value,
    "toWireType": (destructors, value) => value,
    "argPackAdvance": GenericWireTypeSize,
    "readValueFromPointer": floatReadValueFromPointer(name, size),
    destructorFunction: null
  })
};
var integerReadValueFromPointer = (name, width, signed) => {
  switch (width) {
    case 1:
      return signed ? pointer => GROWABLE_HEAP_I8()[pointer >> 0] : pointer => GROWABLE_HEAP_U8()[pointer >> 0];
    case 2:
      return signed ? pointer => GROWABLE_HEAP_I16()[pointer >> 1] : pointer => GROWABLE_HEAP_U16()[pointer >> 1];
    case 4:
      return signed ? pointer => GROWABLE_HEAP_I32()[pointer >> 2] : pointer => GROWABLE_HEAP_U32()[pointer >> 2];
    default:
      throw new TypeError(`invalid integer width (${width}): ${name}`)
  }
};
var __embind_register_integer = (primitiveType, name, size, minRange, maxRange) => {
  name = readLatin1String(name);
  if (maxRange === -1) {
    maxRange = 4294967295
  }
  var fromWireType = value => value;
  if (minRange === 0) {
    var bitshift = 32 - 8 * size;
    fromWireType = value => value << bitshift >>> bitshift
  }
  var isUnsignedType = name.includes("unsigned");
  var checkAssertions = (value, toTypeName) => {};
  var toWireType;
  if (isUnsignedType) {
    toWireType = function (destructors, value) {
      checkAssertions(value, this.name);
      return value >>> 0
    }
  } else {
    toWireType = function (destructors, value) {
      checkAssertions(value, this.name);
      return value
    }
  }
  registerType(primitiveType, {
    name: name,
    "fromWireType": fromWireType,
    "toWireType": toWireType,
    "argPackAdvance": GenericWireTypeSize,
    "readValueFromPointer": integerReadValueFromPointer(name, size, minRange !== 0),
    destructorFunction: null
  })
};
var __embind_register_memory_view = (rawType, dataTypeIndex, name) => {
  var typeMapping = [Int8Array, Uint8Array, Int16Array, Uint16Array, Int32Array, Uint32Array, Float32Array, Float64Array];
  var TA = typeMapping[dataTypeIndex];

  function decodeMemoryView(handle) {
    var size = GROWABLE_HEAP_U32()[handle >> 2];
    var data = GROWABLE_HEAP_U32()[handle + 4 >> 2];
    return new TA(GROWABLE_HEAP_I8().buffer, data, size)
  }
  name = readLatin1String(name);
  registerType(rawType, {
    name: name,
    "fromWireType": decodeMemoryView,
    "argPackAdvance": GenericWireTypeSize,
    "readValueFromPointer": decodeMemoryView
  }, {
    ignoreDuplicateRegistrations: true
  })
};

function readPointer(pointer) {
  return this["fromWireType"](GROWABLE_HEAP_U32()[pointer >> 2])
}
var stringToUTF8 = (str, outPtr, maxBytesToWrite) => stringToUTF8Array(str, GROWABLE_HEAP_U8(), outPtr, maxBytesToWrite);
var __embind_register_std_string = (rawType, name) => {
  name = readLatin1String(name);
  var stdStringIsUTF8 = name === "std::string";
  registerType(rawType, {
    name: name,
    "fromWireType"(value) {
      var length = GROWABLE_HEAP_U32()[value >> 2];
      var payload = value + 4;
      var str;
      if (stdStringIsUTF8) {
        var decodeStartPtr = payload;
        for (var i = 0; i <= length; ++i) {
          var currentBytePtr = payload + i;
          if (i == length || GROWABLE_HEAP_U8()[currentBytePtr] == 0) {
            var maxRead = currentBytePtr - decodeStartPtr;
            var stringSegment = UTF8ToString(decodeStartPtr, maxRead);
            if (str === undefined) {
              str = stringSegment
            } else {
              str += String.fromCharCode(0);
              str += stringSegment
            }
            decodeStartPtr = currentBytePtr + 1
          }
        }
      } else {
        var a = new Array(length);
        for (var i = 0; i < length; ++i) {
          a[i] = String.fromCharCode(GROWABLE_HEAP_U8()[payload + i])
        }
        str = a.join("")
      }
      _free(value);
      return str
    },
    "toWireType"(destructors, value) {
      if (value instanceof ArrayBuffer) {
        value = new Uint8Array(value)
      }
      var length;
      var valueIsOfTypeString = typeof value == "string";
      if (!(valueIsOfTypeString || value instanceof Uint8Array || value instanceof Uint8ClampedArray || value instanceof Int8Array)) {
        throwBindingError("Cannot pass non-string to std::string")
      }
      if (stdStringIsUTF8 && valueIsOfTypeString) {
        length = lengthBytesUTF8(value)
      } else {
        length = value.length
      }
      var base = _malloc(4 + length + 1);
      var ptr = base + 4;
      GROWABLE_HEAP_U32()[base >> 2] = length;
      if (stdStringIsUTF8 && valueIsOfTypeString) {
        stringToUTF8(value, ptr, length + 1)
      } else {
        if (valueIsOfTypeString) {
          for (var i = 0; i < length; ++i) {
            var charCode = value.charCodeAt(i);
            if (charCode > 255) {
              _free(ptr);
              throwBindingError("String has UTF-16 code units that do not fit in 8 bits")
            }
            GROWABLE_HEAP_U8()[ptr + i] = charCode
          }
        } else {
          for (var i = 0; i < length; ++i) {
            GROWABLE_HEAP_U8()[ptr + i] = value[i]
          }
        }
      }
      if (destructors !== null) {
        destructors.push(_free, base)
      }
      return base
    },
    "argPackAdvance": GenericWireTypeSize,
    "readValueFromPointer": readPointer,
    destructorFunction(ptr) {
      _free(ptr)
    }
  })
};
var UTF16Decoder = typeof TextDecoder != "undefined" ? new TextDecoder("utf-16le") : undefined;
var UTF16ToString = (ptr, maxBytesToRead) => {
  var endPtr = ptr;
  var idx = endPtr >> 1;
  var maxIdx = idx + maxBytesToRead / 2;
  while (!(idx >= maxIdx) && GROWABLE_HEAP_U16()[idx]) ++idx;
  endPtr = idx << 1;
  if (endPtr - ptr > 32 && UTF16Decoder) return UTF16Decoder.decode(GROWABLE_HEAP_U8().slice(ptr, endPtr));
  var str = "";
  for (var i = 0; !(i >= maxBytesToRead / 2); ++i) {
    var codeUnit = GROWABLE_HEAP_I16()[ptr + i * 2 >> 1];
    if (codeUnit == 0) break;
    str += String.fromCharCode(codeUnit)
  }
  return str
};
var stringToUTF16 = (str, outPtr, maxBytesToWrite) => {
  if (maxBytesToWrite === undefined) {
    maxBytesToWrite = 2147483647
  }
  if (maxBytesToWrite < 2) return 0;
  maxBytesToWrite -= 2;
  var startPtr = outPtr;
  var numCharsToWrite = maxBytesToWrite < str.length * 2 ? maxBytesToWrite / 2 : str.length;
  for (var i = 0; i < numCharsToWrite; ++i) {
    var codeUnit = str.charCodeAt(i);
    GROWABLE_HEAP_I16()[outPtr >> 1] = codeUnit;
    outPtr += 2
  }
  GROWABLE_HEAP_I16()[outPtr >> 1] = 0;
  return outPtr - startPtr
};
var lengthBytesUTF16 = str => str.length * 2;
var UTF32ToString = (ptr, maxBytesToRead) => {
  var i = 0;
  var str = "";
  while (!(i >= maxBytesToRead / 4)) {
    var utf32 = GROWABLE_HEAP_I32()[ptr + i * 4 >> 2];
    if (utf32 == 0) break;
    ++i;
    if (utf32 >= 65536) {
      var ch = utf32 - 65536;
      str += String.fromCharCode(55296 | ch >> 10, 56320 | ch & 1023)
    } else {
      str += String.fromCharCode(utf32)
    }
  }
  return str
};
var stringToUTF32 = (str, outPtr, maxBytesToWrite) => {
  if (maxBytesToWrite === undefined) {
    maxBytesToWrite = 2147483647
  }
  if (maxBytesToWrite < 4) return 0;
  var startPtr = outPtr;
  var endPtr = startPtr + maxBytesToWrite - 4;
  for (var i = 0; i < str.length; ++i) {
    var codeUnit = str.charCodeAt(i);
    if (codeUnit >= 55296 && codeUnit <= 57343) {
      var trailSurrogate = str.charCodeAt(++i);
      codeUnit = 65536 + ((codeUnit & 1023) << 10) | trailSurrogate & 1023
    }
    GROWABLE_HEAP_I32()[outPtr >> 2] = codeUnit;
    outPtr += 4;
    if (outPtr + 4 > endPtr) break
  }
  GROWABLE_HEAP_I32()[outPtr >> 2] = 0;
  return outPtr - startPtr
};
var lengthBytesUTF32 = str => {
  var len = 0;
  for (var i = 0; i < str.length; ++i) {
    var codeUnit = str.charCodeAt(i);
    if (codeUnit >= 55296 && codeUnit <= 57343) ++i;
    len += 4
  }
  return len
};
var __embind_register_std_wstring = (rawType, charSize, name) => {
  name = readLatin1String(name);
  var decodeString, encodeString, getHeap, lengthBytesUTF, shift;
  if (charSize === 2) {
    decodeString = UTF16ToString;
    encodeString = stringToUTF16;
    lengthBytesUTF = lengthBytesUTF16;
    getHeap = () => GROWABLE_HEAP_U16();
    shift = 1
  } else if (charSize === 4) {
    decodeString = UTF32ToString;
    encodeString = stringToUTF32;
    lengthBytesUTF = lengthBytesUTF32;
    getHeap = () => GROWABLE_HEAP_U32();
    shift = 2
  }
  registerType(rawType, {
    name: name,
    "fromWireType": value => {
      var length = GROWABLE_HEAP_U32()[value >> 2];
      var HEAP = getHeap();
      var str;
      var decodeStartPtr = value + 4;
      for (var i = 0; i <= length; ++i) {
        var currentBytePtr = value + 4 + i * charSize;
        if (i == length || HEAP[currentBytePtr >> shift] == 0) {
          var maxReadBytes = currentBytePtr - decodeStartPtr;
          var stringSegment = decodeString(decodeStartPtr, maxReadBytes);
          if (str === undefined) {
            str = stringSegment
          } else {
            str += String.fromCharCode(0);
            str += stringSegment
          }
          decodeStartPtr = currentBytePtr + charSize
        }
      }
      _free(value);
      return str
    },
    "toWireType": (destructors, value) => {
      if (!(typeof value == "string")) {
        throwBindingError(`Cannot pass non-string to C++ string type ${name}`)
      }
      var length = lengthBytesUTF(value);
      var ptr = _malloc(4 + length + charSize);
      GROWABLE_HEAP_U32()[ptr >> 2] = length >> shift;
      encodeString(value, ptr + 4, length + charSize);
      if (destructors !== null) {
        destructors.push(_free, ptr)
      }
      return ptr
    },
    "argPackAdvance": GenericWireTypeSize,
    "readValueFromPointer": simpleReadValueFromPointer,
    destructorFunction(ptr) {
      _free(ptr)
    }
  })
};
var __embind_register_void = (rawType, name) => {
  name = readLatin1String(name);
  registerType(rawType, {
    isVoid: true,
    name: name,
    "argPackAdvance": 0,
    "fromWireType": () => undefined,
    "toWireType": (destructors, o) => undefined
  })
};
var nowIsMonotonic = true;
var __emscripten_get_now_is_monotonic = () => nowIsMonotonic;
var maybeExit = () => {
  if (!keepRuntimeAlive()) {
    try {
      if (ENVIRONMENT_IS_PTHREAD) __emscripten_thread_exit(EXITSTATUS);
      else _exit(EXITSTATUS)
    } catch (e) {
      handleException(e)
    }
  }
};
var callUserCallback = func => {
  if (ABORT) {
    return
  }
  try {
    func();
    maybeExit()
  } catch (e) {
    handleException(e)
  }
};
var __emscripten_thread_mailbox_await = pthread_ptr => {
  if (typeof Atomics.waitAsync === "function") {
    var wait = Atomics.waitAsync(GROWABLE_HEAP_I32(), pthread_ptr >> 2, pthread_ptr);
    wait.value.then(checkMailbox);
    var waitingAsync = pthread_ptr + 128;
    Atomics.store(GROWABLE_HEAP_I32(), waitingAsync >> 2, 1)
  }
};
Module["__emscripten_thread_mailbox_await"] = __emscripten_thread_mailbox_await;
var checkMailbox = () => {
  var pthread_ptr = _pthread_self();
  if (pthread_ptr) {
    __emscripten_thread_mailbox_await(pthread_ptr);
    callUserCallback(() => __emscripten_check_mailbox())
  }
};
Module["checkMailbox"] = checkMailbox;
var __emscripten_notify_mailbox_postmessage = (targetThreadId, currThreadId, mainThreadId) => {
  if (targetThreadId == currThreadId) {
    setTimeout(() => checkMailbox())
  } else if (ENVIRONMENT_IS_PTHREAD) {
    postMessage({
      "targetThread": targetThreadId,
      "cmd": "checkMailbox"
    })
  } else {
    var worker = PThread.pthreads[targetThreadId];
    if (!worker) {
      return
    }
    worker.postMessage({
      "cmd": "checkMailbox"
    })
  }
};
var withStackSave = f => {
  var stack = stackSave();
  var ret = f();
  stackRestore(stack);
  return ret
};
var proxyToMainThread = function (index, sync) {
  var numCallArgs = arguments.length - 2;
  var outerArgs = arguments;
  return withStackSave(() => {
    var serializedNumCallArgs = numCallArgs;
    var args = stackAlloc(serializedNumCallArgs * 8);
    var b = args >> 3;
    for (var i = 0; i < numCallArgs; i++) {
      var arg = outerArgs[2 + i];
      GROWABLE_HEAP_F64()[b + i] = arg
    }
    return __emscripten_run_on_main_thread_js(index, serializedNumCallArgs, args, sync)
  })
};
var proxiedJSCallArgs = [];
var __emscripten_receive_on_main_thread_js = (index, callingThread, numCallArgs, args) => {
  proxiedJSCallArgs.length = numCallArgs;
  var b = args >> 3;
  for (var i = 0; i < numCallArgs; i++) {
    proxiedJSCallArgs[i] = GROWABLE_HEAP_F64()[b + i]
  }
  var func = proxiedFunctionTable[index];
  PThread.currentProxiedOperationCallerThread = callingThread;
  var rtn = func.apply(null, proxiedJSCallArgs);
  PThread.currentProxiedOperationCallerThread = 0;
  return rtn
};
var __emscripten_thread_set_strongref = thread => {
  if (ENVIRONMENT_IS_NODE) {
    PThread.pthreads[thread].ref()
  }
};
var _abort = () => {
  abort("")
};
var runtimeKeepalivePush = () => {
  runtimeKeepaliveCounter += 1
};
var _emscripten_set_main_loop_timing = (mode, value) => {
  Browser.mainLoop.timingMode = mode;
  Browser.mainLoop.timingValue = value;
  if (!Browser.mainLoop.func) {
    return 1
  }
  if (!Browser.mainLoop.running) {
    runtimeKeepalivePush();
    Browser.mainLoop.running = true
  }
  if (mode == 0) {
    Browser.mainLoop.scheduler = function Browser_mainLoop_scheduler_setTimeout() {
      var timeUntilNextTick = Math.max(0, Browser.mainLoop.tickStartTime + value - _emscripten_get_now()) | 0;
      setTimeout(Browser.mainLoop.runner, timeUntilNextTick)
    };
    Browser.mainLoop.method = "timeout"
  } else if (mode == 1) {
    Browser.mainLoop.scheduler = function Browser_mainLoop_scheduler_rAF() {
      Browser.requestAnimationFrame(Browser.mainLoop.runner)
    };
    Browser.mainLoop.method = "rAF"
  } else if (mode == 2) {
    if (typeof setImmediate == "undefined") {
      var setImmediates = [];
      var emscriptenMainLoopMessageId = "setimmediate";
      var Browser_setImmediate_messageHandler = event => {
        if (event.data === emscriptenMainLoopMessageId || event.data.target === emscriptenMainLoopMessageId) {
          event.stopPropagation();
          setImmediates.shift()()
        }
      };
      addEventListener("message", Browser_setImmediate_messageHandler, true);
      setImmediate = function Browser_emulated_setImmediate(func) {
        setImmediates.push(func);
        if (ENVIRONMENT_IS_WORKER) {
          if (Module["setImmediates"] === undefined) Module["setImmediates"] = [];
          Module["setImmediates"].push(func);
          postMessage({
            target: emscriptenMainLoopMessageId
          })
        } else postMessage(emscriptenMainLoopMessageId, "*")
      }
    }
    Browser.mainLoop.scheduler = function Browser_mainLoop_scheduler_setImmediate() {
      setImmediate(Browser.mainLoop.runner)
    };
    Browser.mainLoop.method = "immediate"
  }
  return 0
};
var _emscripten_get_now;
_emscripten_get_now = () => performance.timeOrigin + performance.now();
var runtimeKeepalivePop = () => {
  runtimeKeepaliveCounter -= 1
};
var setMainLoop = (browserIterationFunc, fps, simulateInfiniteLoop, arg, noSetTiming) => {
  assert(!Browser.mainLoop.func, "emscripten_set_main_loop: there can only be one main loop function at once: call emscripten_cancel_main_loop to cancel the previous one before setting a new one with different parameters.");
  Browser.mainLoop.func = browserIterationFunc;
  Browser.mainLoop.arg = arg;
  var thisMainLoopId = Browser.mainLoop.currentlyRunningMainloop;

  function checkIsRunning() {
    if (thisMainLoopId < Browser.mainLoop.currentlyRunningMainloop) {
      runtimeKeepalivePop();
      return false
    }
    return true
  }
  Browser.mainLoop.running = false;
  Browser.mainLoop.runner = function Browser_mainLoop_runner() {
    if (ABORT) return;
    if (Browser.mainLoop.queue.length > 0) {
      var start = Date.now();
      var blocker = Browser.mainLoop.queue.shift();
      blocker.func(blocker.arg);
      if (Browser.mainLoop.remainingBlockers) {
        var remaining = Browser.mainLoop.remainingBlockers;
        var next = remaining % 1 == 0 ? remaining - 1 : Math.floor(remaining);
        if (blocker.counted) {
          Browser.mainLoop.remainingBlockers = next
        } else {
          next = next + .5;
          Browser.mainLoop.remainingBlockers = (8 * remaining + next) / 9
        }
      }
      Browser.mainLoop.updateStatus();
      if (!checkIsRunning()) return;
      setTimeout(Browser.mainLoop.runner, 0);
      return
    }
    if (!checkIsRunning()) return;
    Browser.mainLoop.currentFrameNumber = Browser.mainLoop.currentFrameNumber + 1 | 0;
    if (Browser.mainLoop.timingMode == 1 && Browser.mainLoop.timingValue > 1 && Browser.mainLoop.currentFrameNumber % Browser.mainLoop.timingValue != 0) {
      Browser.mainLoop.scheduler();
      return
    } else if (Browser.mainLoop.timingMode == 0) {
      Browser.mainLoop.tickStartTime = _emscripten_get_now()
    }
    Browser.mainLoop.runIter(browserIterationFunc);
    if (!checkIsRunning()) return;
    if (typeof SDL == "object" && SDL.audio && SDL.audio.queueNewAudioData) SDL.audio.queueNewAudioData();
    Browser.mainLoop.scheduler()
  };
  if (!noSetTiming) {
    if (fps && fps > 0) {
      _emscripten_set_main_loop_timing(0, 1e3 / fps)
    } else {
      _emscripten_set_main_loop_timing(1, 1)
    }
    Browser.mainLoop.scheduler()
  }
  if (simulateInfiniteLoop) {
    throw "unwind"
  }
};
var safeSetTimeout = (func, timeout) => {
  runtimeKeepalivePush();
  return setTimeout(() => {
    runtimeKeepalivePop();
    callUserCallback(func)
  }, timeout)
};
var warnOnce = text => {
  if (!warnOnce.shown) warnOnce.shown = {};
  if (!warnOnce.shown[text]) {
    warnOnce.shown[text] = 1;
    if (ENVIRONMENT_IS_NODE) text = "warning: " + text;
    err(text)
  }
};
var Browser = {
  mainLoop: {
    running: false,
    scheduler: null,
    method: "",
    currentlyRunningMainloop: 0,
    func: null,
    arg: 0,
    timingMode: 0,
    timingValue: 0,
    currentFrameNumber: 0,
    queue: [],
    pause() {
      Browser.mainLoop.scheduler = null;
      Browser.mainLoop.currentlyRunningMainloop++
    },
    resume() {
      Browser.mainLoop.currentlyRunningMainloop++;
      var timingMode = Browser.mainLoop.timingMode;
      var timingValue = Browser.mainLoop.timingValue;
      var func = Browser.mainLoop.func;
      Browser.mainLoop.func = null;
      setMainLoop(func, 0, false, Browser.mainLoop.arg, true);
      _emscripten_set_main_loop_timing(timingMode, timingValue);
      Browser.mainLoop.scheduler()
    },
    updateStatus() {
      if (Module["setStatus"]) {
        var message = Module["statusMessage"] || "Please wait...";
        var remaining = Browser.mainLoop.remainingBlockers;
        var expected = Browser.mainLoop.expectedBlockers;
        if (remaining) {
          if (remaining < expected) {
            Module["setStatus"](message + " (" + (expected - remaining) + "/" + expected + ")")
          } else {
            Module["setStatus"](message)
          }
        } else {
          Module["setStatus"]("")
        }
      }
    },
    runIter(func) {
      if (ABORT) return;
      if (Module["preMainLoop"]) {
        var preRet = Module["preMainLoop"]();
        if (preRet === false) {
          return
        }
      }
      callUserCallback(func);
      if (Module["postMainLoop"]) Module["postMainLoop"]()
    }
  },
  isFullscreen: false,
  pointerLock: false,
  moduleContextCreatedCallbacks: [],
  workers: [],
  init() {
    if (Browser.initted) return;
    Browser.initted = true;
    var imagePlugin = {};
    imagePlugin["canHandle"] = function imagePlugin_canHandle(name) {
      return !Module.noImageDecoding && /\.(jpg|jpeg|png|bmp)$/i.test(name)
    };
    imagePlugin["handle"] = function imagePlugin_handle(byteArray, name, onload, onerror) {
      var b = new Blob([byteArray], {
        type: Browser.getMimetype(name)
      });
      if (b.size !== byteArray.length) {
        b = new Blob([new Uint8Array(byteArray).buffer], {
          type: Browser.getMimetype(name)
        })
      }
      var url = URL.createObjectURL(b);
      var img = new Image;
      img.onload = () => {
        assert(img.complete, `Image ${name} could not be decoded`);
        var canvas = document.createElement("canvas");
        canvas.width = img.width;
        canvas.height = img.height;
        var ctx = canvas.getContext("2d");
        ctx.drawImage(img, 0, 0);
        preloadedImages[name] = canvas;
        URL.revokeObjectURL(url);
        if (onload) onload(byteArray)
      };
      img.onerror = event => {
        err(`Image ${url} could not be decoded`);
        if (onerror) onerror()
      };
      img.src = url
    };
    preloadPlugins.push(imagePlugin);
    var audioPlugin = {};
    audioPlugin["canHandle"] = function audioPlugin_canHandle(name) {
      return !Module.noAudioDecoding && name.substr(-4) in {
        ".ogg": 1,
        ".wav": 1,
        ".mp3": 1
      }
    };
    audioPlugin["handle"] = function audioPlugin_handle(byteArray, name, onload, onerror) {
      var done = false;

      function finish(audio) {
        if (done) return;
        done = true;
        preloadedAudios[name] = audio;
        if (onload) onload(byteArray)
      }
      var b = new Blob([byteArray], {
        type: Browser.getMimetype(name)
      });
      var url = URL.createObjectURL(b);
      var audio = new Audio;
      audio.addEventListener("canplaythrough", () => finish(audio), false);
      audio.onerror = function audio_onerror(event) {
        if (done) return;
        err(`warning: browser could not fully decode audio ${name}, trying slower base64 approach`);

        function encode64(data) {
          var BASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
          var PAD = "=";
          var ret = "";
          var leftchar = 0;
          var leftbits = 0;
          for (var i = 0; i < data.length; i++) {
            leftchar = leftchar << 8 | data[i];
            leftbits += 8;
            while (leftbits >= 6) {
              var curr = leftchar >> leftbits - 6 & 63;
              leftbits -= 6;
              ret += BASE[curr]
            }
          }
          if (leftbits == 2) {
            ret += BASE[(leftchar & 3) << 4];
            ret += PAD + PAD
          } else if (leftbits == 4) {
            ret += BASE[(leftchar & 15) << 2];
            ret += PAD
          }
          return ret
        }
        audio.src = "data:audio/x-" + name.substr(-3) + ";base64," + encode64(byteArray);
        finish(audio)
      };
      audio.src = url;
      safeSetTimeout(() => {
        finish(audio)
      }, 1e4)
    };
    preloadPlugins.push(audioPlugin);

    function pointerLockChange() {
      Browser.pointerLock = document["pointerLockElement"] === Module["canvas"] || document["mozPointerLockElement"] === Module["canvas"] || document["webkitPointerLockElement"] === Module["canvas"] || document["msPointerLockElement"] === Module["canvas"]
    }
    var canvas = Module["canvas"];
    if (canvas) {
      canvas.requestPointerLock = canvas["requestPointerLock"] || canvas["mozRequestPointerLock"] || canvas["webkitRequestPointerLock"] || canvas["msRequestPointerLock"] || (() => {});
      canvas.exitPointerLock = document["exitPointerLock"] || document["mozExitPointerLock"] || document["webkitExitPointerLock"] || document["msExitPointerLock"] || (() => {});
      canvas.exitPointerLock = canvas.exitPointerLock.bind(document);
      document.addEventListener("pointerlockchange", pointerLockChange, false);
      document.addEventListener("mozpointerlockchange", pointerLockChange, false);
      document.addEventListener("webkitpointerlockchange", pointerLockChange, false);
      document.addEventListener("mspointerlockchange", pointerLockChange, false);
      if (Module["elementPointerLock"]) {
        canvas.addEventListener("click", ev => {
          if (!Browser.pointerLock && Module["canvas"].requestPointerLock) {
            Module["canvas"].requestPointerLock();
            ev.preventDefault()
          }
        }, false)
      }
    }
  },
  createContext(canvas, useWebGL, setInModule, webGLContextAttributes) {
    if (useWebGL && Module.ctx && canvas == Module.canvas) return Module.ctx;
    var ctx;
    var contextHandle;
    if (useWebGL) {
      var contextAttributes = {
        antialias: false,
        alpha: false,
        majorVersion: typeof WebGL2RenderingContext != "undefined" ? 2 : 1
      };
      if (webGLContextAttributes) {
        for (var attribute in webGLContextAttributes) {
          contextAttributes[attribute] = webGLContextAttributes[attribute]
        }
      }
      if (typeof GL != "undefined") {
        contextHandle = GL.createContext(canvas, contextAttributes);
        if (contextHandle) {
          ctx = GL.getContext(contextHandle).GLctx
        }
      }
    } else {
      ctx = canvas.getContext("2d")
    }
    if (!ctx) return null;
    if (setInModule) {
      if (!useWebGL) assert(typeof GLctx == "undefined", "cannot set in module if GLctx is used, but we are a non-GL context that would replace it");
      Module.ctx = ctx;
      if (useWebGL) GL.makeContextCurrent(contextHandle);
      Module.useWebGL = useWebGL;
      Browser.moduleContextCreatedCallbacks.forEach(callback => callback());
      Browser.init()
    }
    return ctx
  },
  destroyContext(canvas, useWebGL, setInModule) {},
  fullscreenHandlersInstalled: false,
  lockPointer: undefined,
  resizeCanvas: undefined,
  requestFullscreen(lockPointer, resizeCanvas) {
    Browser.lockPointer = lockPointer;
    Browser.resizeCanvas = resizeCanvas;
    if (typeof Browser.lockPointer == "undefined") Browser.lockPointer = true;
    if (typeof Browser.resizeCanvas == "undefined") Browser.resizeCanvas = false;
    var canvas = Module["canvas"];

    function fullscreenChange() {
      Browser.isFullscreen = false;
      var canvasContainer = canvas.parentNode;
      if ((document["fullscreenElement"] || document["mozFullScreenElement"] || document["msFullscreenElement"] || document["webkitFullscreenElement"] || document["webkitCurrentFullScreenElement"]) === canvasContainer) {
        canvas.exitFullscreen = Browser.exitFullscreen;
        if (Browser.lockPointer) canvas.requestPointerLock();
        Browser.isFullscreen = true;
        if (Browser.resizeCanvas) {
          Browser.setFullscreenCanvasSize()
        } else {
          Browser.updateCanvasDimensions(canvas)
        }
      } else {
        canvasContainer.parentNode.insertBefore(canvas, canvasContainer);
        canvasContainer.parentNode.removeChild(canvasContainer);
        if (Browser.resizeCanvas) {
          Browser.setWindowedCanvasSize()
        } else {
          Browser.updateCanvasDimensions(canvas)
        }
      }
      if (Module["onFullScreen"]) Module["onFullScreen"](Browser.isFullscreen);
      if (Module["onFullscreen"]) Module["onFullscreen"](Browser.isFullscreen)
    }
    if (!Browser.fullscreenHandlersInstalled) {
      Browser.fullscreenHandlersInstalled = true;
      document.addEventListener("fullscreenchange", fullscreenChange, false);
      document.addEventListener("mozfullscreenchange", fullscreenChange, false);
      document.addEventListener("webkitfullscreenchange", fullscreenChange, false);
      document.addEventListener("MSFullscreenChange", fullscreenChange, false)
    }
    var canvasContainer = document.createElement("div");
    canvas.parentNode.insertBefore(canvasContainer, canvas);
    canvasContainer.appendChild(canvas);
    canvasContainer.requestFullscreen = canvasContainer["requestFullscreen"] || canvasContainer["mozRequestFullScreen"] || canvasContainer["msRequestFullscreen"] || (canvasContainer["webkitRequestFullscreen"] ? () => canvasContainer["webkitRequestFullscreen"](Element["ALLOW_KEYBOARD_INPUT"]) : null) || (canvasContainer["webkitRequestFullScreen"] ? () => canvasContainer["webkitRequestFullScreen"](Element["ALLOW_KEYBOARD_INPUT"]) : null);
    canvasContainer.requestFullscreen()
  },
  exitFullscreen() {
    if (!Browser.isFullscreen) {
      return false
    }
    var CFS = document["exitFullscreen"] || document["cancelFullScreen"] || document["mozCancelFullScreen"] || document["msExitFullscreen"] || document["webkitCancelFullScreen"] || (() => {});
    CFS.apply(document, []);
    return true
  },
  nextRAF: 0,
  fakeRequestAnimationFrame(func) {
    var now = Date.now();
    if (Browser.nextRAF === 0) {
      Browser.nextRAF = now + 1e3 / 60
    } else {
      while (now + 2 >= Browser.nextRAF) {
        Browser.nextRAF += 1e3 / 60
      }
    }
    var delay = Math.max(Browser.nextRAF - now, 0);
    setTimeout(func, delay)
  },
  requestAnimationFrame(func) {
    if (typeof requestAnimationFrame == "function") {
      requestAnimationFrame(func);
      return
    }
    var RAF = Browser.fakeRequestAnimationFrame;
    RAF(func)
  },
  safeSetTimeout(func, timeout) {
    return safeSetTimeout(func, timeout)
  },
  safeRequestAnimationFrame(func) {
    runtimeKeepalivePush();
    return Browser.requestAnimationFrame(() => {
      runtimeKeepalivePop();
      callUserCallback(func)
    })
  },
  getMimetype(name) {
    return {
      "jpg": "image/jpeg",
      "jpeg": "image/jpeg",
      "png": "image/png",
      "bmp": "image/bmp",
      "ogg": "audio/ogg",
      "wav": "audio/wav",
      "mp3": "audio/mpeg"
    } [name.substr(name.lastIndexOf(".") + 1)]
  },
  getUserMedia(func) {
    if (!window.getUserMedia) {
      window.getUserMedia = navigator["getUserMedia"] || navigator["mozGetUserMedia"]
    }
    window.getUserMedia(func)
  },
  getMovementX(event) {
    return event["movementX"] || event["mozMovementX"] || event["webkitMovementX"] || 0
  },
  getMovementY(event) {
    return event["movementY"] || event["mozMovementY"] || event["webkitMovementY"] || 0
  },
  getMouseWheelDelta(event) {
    var delta = 0;
    switch (event.type) {
      case "DOMMouseScroll":
        delta = event.detail / 3;
        break;
      case "mousewheel":
        delta = event.wheelDelta / 120;
        break;
      case "wheel":
        delta = event.deltaY;
        switch (event.deltaMode) {
          case 0:
            delta /= 100;
            break;
          case 1:
            delta /= 3;
            break;
          case 2:
            delta *= 80;
            break;
          default:
            throw "unrecognized mouse wheel delta mode: " + event.deltaMode
        }
        break;
      default:
        throw "unrecognized mouse wheel event: " + event.type
    }
    return delta
  },
  mouseX: 0,
  mouseY: 0,
  mouseMovementX: 0,
  mouseMovementY: 0,
  touches: {},
  lastTouches: {},
  calculateMouseEvent(event) {
    if (Browser.pointerLock) {
      if (event.type != "mousemove" && "mozMovementX" in event) {
        Browser.mouseMovementX = Browser.mouseMovementY = 0
      } else {
        Browser.mouseMovementX = Browser.getMovementX(event);
        Browser.mouseMovementY = Browser.getMovementY(event)
      }
      if (typeof SDL != "undefined") {
        Browser.mouseX = SDL.mouseX + Browser.mouseMovementX;
        Browser.mouseY = SDL.mouseY + Browser.mouseMovementY
      } else {
        Browser.mouseX += Browser.mouseMovementX;
        Browser.mouseY += Browser.mouseMovementY
      }
    } else {
      var rect = Module["canvas"].getBoundingClientRect();
      var cw = Module["canvas"].width;
      var ch = Module["canvas"].height;
      var scrollX = typeof window.scrollX != "undefined" ? window.scrollX : window.pageXOffset;
      var scrollY = typeof window.scrollY != "undefined" ? window.scrollY : window.pageYOffset;
      if (event.type === "touchstart" || event.type === "touchend" || event.type === "touchmove") {
        var touch = event.touch;
        if (touch === undefined) {
          return
        }
        var adjustedX = touch.pageX - (scrollX + rect.left);
        var adjustedY = touch.pageY - (scrollY + rect.top);
        adjustedX = adjustedX * (cw / rect.width);
        adjustedY = adjustedY * (ch / rect.height);
        var coords = {
          x: adjustedX,
          y: adjustedY
        };
        if (event.type === "touchstart") {
          Browser.lastTouches[touch.identifier] = coords;
          Browser.touches[touch.identifier] = coords
        } else if (event.type === "touchend" || event.type === "touchmove") {
          var last = Browser.touches[touch.identifier];
          if (!last) last = coords;
          Browser.lastTouches[touch.identifier] = last;
          Browser.touches[touch.identifier] = coords
        }
        return
      }
      var x = event.pageX - (scrollX + rect.left);
      var y = event.pageY - (scrollY + rect.top);
      x = x * (cw / rect.width);
      y = y * (ch / rect.height);
      Browser.mouseMovementX = x - Browser.mouseX;
      Browser.mouseMovementY = y - Browser.mouseY;
      Browser.mouseX = x;
      Browser.mouseY = y
    }
  },
  resizeListeners: [],
  updateResizeListeners() {
    var canvas = Module["canvas"];
    Browser.resizeListeners.forEach(listener => listener(canvas.width, canvas.height))
  },
  setCanvasSize(width, height, noUpdates) {
    var canvas = Module["canvas"];
    Browser.updateCanvasDimensions(canvas, width, height);
    if (!noUpdates) Browser.updateResizeListeners()
  },
  windowedWidth: 0,
  windowedHeight: 0,
  setFullscreenCanvasSize() {
    if (typeof SDL != "undefined") {
      var flags = GROWABLE_HEAP_U32()[SDL.screen >> 2];
      flags = flags | 8388608;
      GROWABLE_HEAP_I32()[SDL.screen >> 2] = flags
    }
    Browser.updateCanvasDimensions(Module["canvas"]);
    Browser.updateResizeListeners()
  },
  setWindowedCanvasSize() {
    if (typeof SDL != "undefined") {
      var flags = GROWABLE_HEAP_U32()[SDL.screen >> 2];
      flags = flags & ~8388608;
      GROWABLE_HEAP_I32()[SDL.screen >> 2] = flags
    }
    Browser.updateCanvasDimensions(Module["canvas"]);
    Browser.updateResizeListeners()
  },
  updateCanvasDimensions(canvas, wNative, hNative) {
    if (wNative && hNative) {
      canvas.widthNative = wNative;
      canvas.heightNative = hNative
    } else {
      wNative = canvas.widthNative;
      hNative = canvas.heightNative
    }
    var w = wNative;
    var h = hNative;
    if (Module["forcedAspectRatio"] && Module["forcedAspectRatio"] > 0) {
      if (w / h < Module["forcedAspectRatio"]) {
        w = Math.round(h * Module["forcedAspectRatio"])
      } else {
        h = Math.round(w / Module["forcedAspectRatio"])
      }
    }
    if ((document["fullscreenElement"] || document["mozFullScreenElement"] || document["msFullscreenElement"] || document["webkitFullscreenElement"] || document["webkitCurrentFullScreenElement"]) === canvas.parentNode && typeof screen != "undefined") {
      var factor = Math.min(screen.width / w, screen.height / h);
      w = Math.round(w * factor);
      h = Math.round(h * factor)
    }
    if (Browser.resizeCanvas) {
      if (canvas.width != w) canvas.width = w;
      if (canvas.height != h) canvas.height = h;
      if (typeof canvas.style != "undefined") {
        canvas.style.removeProperty("width");
        canvas.style.removeProperty("height")
      }
    } else {
      if (canvas.width != wNative) canvas.width = wNative;
      if (canvas.height != hNative) canvas.height = hNative;
      if (typeof canvas.style != "undefined") {
        if (w != wNative || h != hNative) {
          canvas.style.setProperty("width", w + "px", "important");
          canvas.style.setProperty("height", h + "px", "important")
        } else {
          canvas.style.removeProperty("width");
          canvas.style.removeProperty("height")
        }
      }
    }
  }
};
var _emscripten_cancel_main_loop = () => {
  Browser.mainLoop.pause();
  Browser.mainLoop.func = null
};
var _emscripten_check_blocking_allowed = () => {};
var _emscripten_exit_with_live_runtime = () => {
  runtimeKeepalivePush();
  throw "unwind"
};
var getHeapMax = () => 2130706432;
var growMemory = size => {
  var b = wasmMemory.buffer;
  var pages = (size - b.byteLength + 65535) / 65536;
  try {
    wasmMemory.grow(pages);
    updateMemoryViews();
    return 1
  } catch (e) {}
};
var _emscripten_resize_heap = requestedSize => {
  var oldSize = GROWABLE_HEAP_U8().length;
  requestedSize >>>= 0;
  if (requestedSize <= oldSize) {
    return false
  }
  var maxHeapSize = getHeapMax();
  if (requestedSize > maxHeapSize) {
    return false
  }
  var alignUp = (x, multiple) => x + (multiple - x % multiple) % multiple;
  for (var cutDown = 1; cutDown <= 4; cutDown *= 2) {
    var overGrownHeapSize = oldSize * (1 + .2 / cutDown);
    overGrownHeapSize = Math.min(overGrownHeapSize, requestedSize + 100663296);
    var newSize = Math.min(maxHeapSize, alignUp(Math.max(requestedSize, overGrownHeapSize), 65536));
    var replacement = growMemory(newSize);
    if (replacement) {
      return true
    }
  }
  return false
};
var JSEvents = {
  inEventHandler: 0,
  removeAllEventListeners() {
    for (var i = JSEvents.eventHandlers.length - 1; i >= 0; --i) {
      JSEvents._removeHandler(i)
    }
    JSEvents.eventHandlers = [];
    JSEvents.deferredCalls = []
  },
  registerRemoveEventListeners() {
    if (!JSEvents.removeEventListenersRegistered) {
      __ATEXIT__.push(JSEvents.removeAllEventListeners);
      JSEvents.removeEventListenersRegistered = true
    }
  },
  deferredCalls: [],
  deferCall(targetFunction, precedence, argsList) {
    function arraysHaveEqualContent(arrA, arrB) {
      if (arrA.length != arrB.length) return false;
      for (var i in arrA) {
        if (arrA[i] != arrB[i]) return false
      }
      return true
    }
    for (var i in JSEvents.deferredCalls) {
      var call = JSEvents.deferredCalls[i];
      if (call.targetFunction == targetFunction && arraysHaveEqualContent(call.argsList, argsList)) {
        return
      }
    }
    JSEvents.deferredCalls.push({
      targetFunction: targetFunction,
      precedence: precedence,
      argsList: argsList
    });
    JSEvents.deferredCalls.sort((x, y) => x.precedence < y.precedence)
  },
  removeDeferredCalls(targetFunction) {
    for (var i = 0; i < JSEvents.deferredCalls.length; ++i) {
      if (JSEvents.deferredCalls[i].targetFunction == targetFunction) {
        JSEvents.deferredCalls.splice(i, 1);
        --i
      }
    }
  },
  canPerformEventHandlerRequests() {
    if (navigator.userActivation) {
      return navigator.userActivation.isActive
    }
    return JSEvents.inEventHandler && JSEvents.currentEventHandler.allowsDeferredCalls
  },
  runDeferredCalls() {
    if (!JSEvents.canPerformEventHandlerRequests()) {
      return
    }
    for (var i = 0; i < JSEvents.deferredCalls.length; ++i) {
      var call = JSEvents.deferredCalls[i];
      JSEvents.deferredCalls.splice(i, 1);
      --i;
      call.targetFunction.apply(null, call.argsList)
    }
  },
  eventHandlers: [],
  removeAllHandlersOnTarget: (target, eventTypeString) => {
    for (var i = 0; i < JSEvents.eventHandlers.length; ++i) {
      if (JSEvents.eventHandlers[i].target == target && (!eventTypeString || eventTypeString == JSEvents.eventHandlers[i].eventTypeString)) {
        JSEvents._removeHandler(i--)
      }
    }
  },
  _removeHandler(i) {
    var h = JSEvents.eventHandlers[i];
    h.target.removeEventListener(h.eventTypeString, h.eventListenerFunc, h.useCapture);
    JSEvents.eventHandlers.splice(i, 1)
  },
  registerOrRemoveHandler(eventHandler) {
    if (!eventHandler.target) {
      return -4
    }
    var jsEventHandler = function jsEventHandler(event) {
      ++JSEvents.inEventHandler;
      JSEvents.currentEventHandler = eventHandler;
      JSEvents.runDeferredCalls();
      eventHandler.handlerFunc(event);
      JSEvents.runDeferredCalls();
      --JSEvents.inEventHandler
    };
    if (eventHandler.callbackfunc) {
      eventHandler.eventListenerFunc = jsEventHandler;
      eventHandler.target.addEventListener(eventHandler.eventTypeString, jsEventHandler, eventHandler.useCapture);
      JSEvents.eventHandlers.push(eventHandler);
      JSEvents.registerRemoveEventListeners()
    } else {
      for (var i = 0; i < JSEvents.eventHandlers.length; ++i) {
        if (JSEvents.eventHandlers[i].target == eventHandler.target && JSEvents.eventHandlers[i].eventTypeString == eventHandler.eventTypeString) {
          JSEvents._removeHandler(i--)
        }
      }
    }
    return 0
  },
  getTargetThreadForEventCallback(targetThread) {
    switch (targetThread) {
      case 1:
        return 0;
      case 2:
        return PThread.currentProxiedOperationCallerThread;
      default:
        return targetThread
    }
  },
  getNodeNameForTarget(target) {
    if (!target) return "";
    if (target == window) return "#window";
    if (target == screen) return "#screen";
    return target && target.nodeName ? target.nodeName : ""
  },
  fullscreenEnabled() {
    return document.fullscreenEnabled || document.webkitFullscreenEnabled
  }
};
var maybeCStringToJsString = cString => cString > 2 ? UTF8ToString(cString) : cString;
var specialHTMLTargets = [0, typeof document != "undefined" ? document : 0, typeof window != "undefined" ? window : 0];
var findEventTarget = target => {
  target = maybeCStringToJsString(target);
  var domElement = specialHTMLTargets[target] || (typeof document != "undefined" ? document.querySelector(target) : undefined);
  return domElement
};
var findCanvasEventTarget = target => findEventTarget(target);
var setCanvasElementSizeCallingThread = (target, width, height) => {
  var canvas = findCanvasEventTarget(target);
  if (!canvas) return -4;
  if (!canvas.controlTransferredOffscreen) {
    var autoResizeViewport = false;
    if (canvas.GLctxObject && canvas.GLctxObject.GLctx) {
      var prevViewport = canvas.GLctxObject.GLctx.getParameter(2978);
      autoResizeViewport = prevViewport[0] === 0 && prevViewport[1] === 0 && prevViewport[2] === canvas.width && prevViewport[3] === canvas.height
    }
    canvas.width = width;
    canvas.height = height;
    if (autoResizeViewport) {
      canvas.GLctxObject.GLctx.viewport(0, 0, width, height)
    }
  } else {
    return -4
  }
  return 0
};

function setCanvasElementSizeMainThread(target, width, height) {
  if (ENVIRONMENT_IS_PTHREAD) return proxyToMainThread(2, 1, target, width, height);
  return setCanvasElementSizeCallingThread(target, width, height)
}
var _emscripten_set_canvas_element_size = (target, width, height) => {
  var canvas = findCanvasEventTarget(target);
  if (canvas) {
    return setCanvasElementSizeCallingThread(target, width, height)
  }
  return setCanvasElementSizeMainThread(target, width, height)
};
var _emscripten_set_main_loop = (func, fps, simulateInfiniteLoop) => {
  var browserIterationFunc = getWasmTableEntry(func);
  setMainLoop(browserIterationFunc, fps, simulateInfiniteLoop)
};
var webgl_enable_ANGLE_instanced_arrays = ctx => {
  var ext = ctx.getExtension("ANGLE_instanced_arrays");
  if (ext) {
    ctx["vertexAttribDivisor"] = (index, divisor) => ext["vertexAttribDivisorANGLE"](index, divisor);
    ctx["drawArraysInstanced"] = (mode, first, count, primcount) => ext["drawArraysInstancedANGLE"](mode, first, count, primcount);
    ctx["drawElementsInstanced"] = (mode, count, type, indices, primcount) => ext["drawElementsInstancedANGLE"](mode, count, type, indices, primcount);
    return 1
  }
};
var webgl_enable_OES_vertex_array_object = ctx => {
  var ext = ctx.getExtension("OES_vertex_array_object");
  if (ext) {
    ctx["createVertexArray"] = () => ext["createVertexArrayOES"]();
    ctx["deleteVertexArray"] = vao => ext["deleteVertexArrayOES"](vao);
    ctx["bindVertexArray"] = vao => ext["bindVertexArrayOES"](vao);
    ctx["isVertexArray"] = vao => ext["isVertexArrayOES"](vao);
    return 1
  }
};
var webgl_enable_WEBGL_draw_buffers = ctx => {
  var ext = ctx.getExtension("WEBGL_draw_buffers");
  if (ext) {
    ctx["drawBuffers"] = (n, bufs) => ext["drawBuffersWEBGL"](n, bufs);
    return 1
  }
};
var webgl_enable_WEBGL_draw_instanced_base_vertex_base_instance = ctx => !!(ctx.dibvbi = ctx.getExtension("WEBGL_draw_instanced_base_vertex_base_instance"));
var webgl_enable_WEBGL_multi_draw_instanced_base_vertex_base_instance = ctx => !!(ctx.mdibvbi = ctx.getExtension("WEBGL_multi_draw_instanced_base_vertex_base_instance"));
var webgl_enable_WEBGL_multi_draw = ctx => !!(ctx.multiDrawWebgl = ctx.getExtension("WEBGL_multi_draw"));
var GL = {
  counter: 1,
  buffers: [],
  programs: [],
  framebuffers: [],
  renderbuffers: [],
  textures: [],
  shaders: [],
  vaos: [],
  contexts: {},
  offscreenCanvases: {},
  queries: [],
  samplers: [],
  transformFeedbacks: [],
  syncs: [],
  stringCache: {},
  stringiCache: {},
  unpackAlignment: 4,
  recordError: function recordError(errorCode) {
    if (!GL.lastError) {
      GL.lastError = errorCode
    }
  },
  getNewId: table => {
    var ret = GL.counter++;
    for (var i = table.length; i < ret; i++) {
      table[i] = null
    }
    return ret
  },
  getSource: (shader, count, string, length) => {
    var source = "";
    for (var i = 0; i < count; ++i) {
      var len = length ? GROWABLE_HEAP_I32()[length + i * 4 >> 2] : -1;
      source += UTF8ToString(GROWABLE_HEAP_I32()[string + i * 4 >> 2], len < 0 ? undefined : len)
    }
    return source
  },
  createContext: (canvas, webGLContextAttributes) => {
    if (!canvas.getContextSafariWebGL2Fixed) {
      canvas.getContextSafariWebGL2Fixed = canvas.getContext;

      function fixedGetContext(ver, attrs) {
        var gl = canvas.getContextSafariWebGL2Fixed(ver, attrs);
        return ver == "webgl" == gl instanceof WebGLRenderingContext ? gl : null
      }
      canvas.getContext = fixedGetContext
    }
    var ctx = webGLContextAttributes.majorVersion > 1 ? canvas.getContext("webgl2", webGLContextAttributes) : canvas.getContext("webgl", webGLContextAttributes);
    if (!ctx) return 0;
    var handle = GL.registerContext(ctx, webGLContextAttributes);
    return handle
  },
  registerContext: (ctx, webGLContextAttributes) => {
    var handle = _malloc(8);
    GROWABLE_HEAP_I32()[handle + 4 >> 2] = _pthread_self();
    var context = {
      handle: handle,
      attributes: webGLContextAttributes,
      version: webGLContextAttributes.majorVersion,
      GLctx: ctx
    };
    if (ctx.canvas) ctx.canvas.GLctxObject = context;
    GL.contexts[handle] = context;
    if (typeof webGLContextAttributes.enableExtensionsByDefault == "undefined" || webGLContextAttributes.enableExtensionsByDefault) {
      GL.initExtensions(context)
    }
    return handle
  },
  makeContextCurrent: contextHandle => {
    GL.currentContext = GL.contexts[contextHandle];
    Module.ctx = GLctx = GL.currentContext && GL.currentContext.GLctx;
    return !(contextHandle && !GLctx)
  },
  getContext: contextHandle => GL.contexts[contextHandle],
  deleteContext: contextHandle => {
    if (GL.currentContext === GL.contexts[contextHandle]) GL.currentContext = null;
    if (typeof JSEvents == "object") JSEvents.removeAllHandlersOnTarget(GL.contexts[contextHandle].GLctx.canvas);
    if (GL.contexts[contextHandle] && GL.contexts[contextHandle].GLctx.canvas) GL.contexts[contextHandle].GLctx.canvas.GLctxObject = undefined;
    _free(GL.contexts[contextHandle].handle);
    GL.contexts[contextHandle] = null
  },
  initExtensions: context => {
    if (!context) context = GL.currentContext;
    if (context.initExtensionsDone) return;
    context.initExtensionsDone = true;
    var GLctx = context.GLctx;
    webgl_enable_ANGLE_instanced_arrays(GLctx);
    webgl_enable_OES_vertex_array_object(GLctx);
    webgl_enable_WEBGL_draw_buffers(GLctx);
    webgl_enable_WEBGL_draw_instanced_base_vertex_base_instance(GLctx);
    webgl_enable_WEBGL_multi_draw_instanced_base_vertex_base_instance(GLctx);
    if (context.version >= 2) {
      GLctx.disjointTimerQueryExt = GLctx.getExtension("EXT_disjoint_timer_query_webgl2")
    }
    if (context.version < 2 || !GLctx.disjointTimerQueryExt) {
      GLctx.disjointTimerQueryExt = GLctx.getExtension("EXT_disjoint_timer_query")
    }
    webgl_enable_WEBGL_multi_draw(GLctx);
    var exts = GLctx.getSupportedExtensions() || [];
    exts.forEach(ext => {
      if (!ext.includes("lose_context") && !ext.includes("debug")) {
        GLctx.getExtension(ext)
      }
    })
  }
};
var emscripten_webgl_power_preferences = ["default", "low-power", "high-performance"];
var _emscripten_webgl_do_create_context = (target, attributes) => {
  var a = attributes >> 2;
  var powerPreference = GROWABLE_HEAP_I32()[a + (24 >> 2)];
  var contextAttributes = {
    "alpha": !!GROWABLE_HEAP_I32()[a + (0 >> 2)],
    "depth": !!GROWABLE_HEAP_I32()[a + (4 >> 2)],
    "stencil": !!GROWABLE_HEAP_I32()[a + (8 >> 2)],
    "antialias": !!GROWABLE_HEAP_I32()[a + (12 >> 2)],
    "premultipliedAlpha": !!GROWABLE_HEAP_I32()[a + (16 >> 2)],
    "preserveDrawingBuffer": !!GROWABLE_HEAP_I32()[a + (20 >> 2)],
    "powerPreference": emscripten_webgl_power_preferences[powerPreference],
    "failIfMajorPerformanceCaveat": !!GROWABLE_HEAP_I32()[a + (28 >> 2)],
    majorVersion: GROWABLE_HEAP_I32()[a + (32 >> 2)],
    minorVersion: GROWABLE_HEAP_I32()[a + (36 >> 2)],
    enableExtensionsByDefault: GROWABLE_HEAP_I32()[a + (40 >> 2)],
    explicitSwapControl: GROWABLE_HEAP_I32()[a + (44 >> 2)],
    proxyContextToMainThread: GROWABLE_HEAP_I32()[a + (48 >> 2)],
    renderViaOffscreenBackBuffer: GROWABLE_HEAP_I32()[a + (52 >> 2)]
  };
  var canvas = findCanvasEventTarget(target);
  if (!canvas) {
    return 0
  }
  if (contextAttributes.explicitSwapControl) {
    return 0
  }
  var contextHandle = GL.createContext(canvas, contextAttributes);
  return contextHandle
};
var _emscripten_webgl_create_context = _emscripten_webgl_do_create_context;
var _emscripten_webgl_destroy_context = contextHandle => {
  if (GL.currentContext == contextHandle) GL.currentContext = 0;
  GL.deleteContext(contextHandle)
};
var _emscripten_webgl_init_context_attributes = attributes => {
  var a = attributes >> 2;
  for (var i = 0; i < 56 >> 2; ++i) {
    GROWABLE_HEAP_I32()[a + i] = 0
  }
  GROWABLE_HEAP_I32()[a + (0 >> 2)] = GROWABLE_HEAP_I32()[a + (4 >> 2)] = GROWABLE_HEAP_I32()[a + (12 >> 2)] = GROWABLE_HEAP_I32()[a + (16 >> 2)] = GROWABLE_HEAP_I32()[a + (32 >> 2)] = GROWABLE_HEAP_I32()[a + (40 >> 2)] = 1;
  if (ENVIRONMENT_IS_WORKER) GROWABLE_HEAP_I32()[attributes + 48 >> 2] = 1
};
var _emscripten_webgl_make_context_current = contextHandle => {
  var success = GL.makeContextCurrent(contextHandle);
  return success ? 0 : -5
};
var ENV = {};
var getExecutableName = () => thisProgram || "./this.program";
var getEnvStrings = () => {
  if (!getEnvStrings.strings) {
    var lang = (typeof navigator == "object" && navigator.languages && navigator.languages[0] || "C").replace("-", "_") + ".UTF-8";
    var env = {
      "USER": "web_user",
      "LOGNAME": "web_user",
      "PATH": "/",
      "PWD": "/",
      "HOME": "/home/web_user",
      "LANG": lang,
      "_": getExecutableName()
    };
    for (var x in ENV) {
      if (ENV[x] === undefined) delete env[x];
      else env[x] = ENV[x]
    }
    var strings = [];
    for (var x in env) {
      strings.push(`${x}=${env[x]}`)
    }
    getEnvStrings.strings = strings
  }
  return getEnvStrings.strings
};
var stringToAscii = (str, buffer) => {
  for (var i = 0; i < str.length; ++i) {
    GROWABLE_HEAP_I8()[buffer++ >> 0] = str.charCodeAt(i)
  }
  GROWABLE_HEAP_I8()[buffer >> 0] = 0
};
var _environ_get = function (__environ, environ_buf) {
  if (ENVIRONMENT_IS_PTHREAD) return proxyToMainThread(3, 1, __environ, environ_buf);
  var bufSize = 0;
  getEnvStrings().forEach((string, i) => {
    var ptr = environ_buf + bufSize;
    GROWABLE_HEAP_U32()[__environ + i * 4 >> 2] = ptr;
    stringToAscii(string, ptr);
    bufSize += string.length + 1
  });
  return 0
};
var _environ_sizes_get = function (penviron_count, penviron_buf_size) {
  if (ENVIRONMENT_IS_PTHREAD) return proxyToMainThread(4, 1, penviron_count, penviron_buf_size);
  var strings = getEnvStrings();
  GROWABLE_HEAP_U32()[penviron_count >> 2] = strings.length;
  var bufSize = 0;
  strings.forEach(string => bufSize += string.length + 1);
  GROWABLE_HEAP_U32()[penviron_buf_size >> 2] = bufSize;
  return 0
};

function _fd_close(fd) {
  if (ENVIRONMENT_IS_PTHREAD) return proxyToMainThread(5, 1, fd);
  try {
    var stream = SYSCALLS.getStreamFromFD(fd);
    FS.close(stream);
    return 0
  } catch (e) {
    if (typeof FS == "undefined" || !(e.name === "ErrnoError")) throw e;
    return e.errno
  }
}
var doReadv = (stream, iov, iovcnt, offset) => {
  var ret = 0;
  for (var i = 0; i < iovcnt; i++) {
    var ptr = GROWABLE_HEAP_U32()[iov >> 2];
    var len = GROWABLE_HEAP_U32()[iov + 4 >> 2];
    iov += 8;
    var curr = FS.read(stream, GROWABLE_HEAP_I8(), ptr, len, offset);
    if (curr < 0) return -1;
    ret += curr;
    if (curr < len) break;
    if (typeof offset !== "undefined") {
      offset += curr
    }
  }
  return ret
};

function _fd_read(fd, iov, iovcnt, pnum) {
  if (ENVIRONMENT_IS_PTHREAD) return proxyToMainThread(6, 1, fd, iov, iovcnt, pnum);
  try {
    var stream = SYSCALLS.getStreamFromFD(fd);
    var num = doReadv(stream, iov, iovcnt);
    GROWABLE_HEAP_U32()[pnum >> 2] = num;
    return 0
  } catch (e) {
    if (typeof FS == "undefined" || !(e.name === "ErrnoError")) throw e;
    return e.errno
  }
}
var convertI32PairToI53Checked = (lo, hi) => hi + 2097152 >>> 0 < 4194305 - !!lo ? (lo >>> 0) + hi * 4294967296 : NaN;

function _fd_seek(fd, offset_low, offset_high, whence, newOffset) {
  if (ENVIRONMENT_IS_PTHREAD) return proxyToMainThread(7, 1, fd, offset_low, offset_high, whence, newOffset);
  var offset = convertI32PairToI53Checked(offset_low, offset_high);
  try {
    if (isNaN(offset)) return 61;
    var stream = SYSCALLS.getStreamFromFD(fd);
    FS.llseek(stream, offset, whence);
    tempI64 = [stream.position >>> 0, (tempDouble = stream.position, +Math.abs(tempDouble) >= 1 ? tempDouble > 0 ? +Math.floor(tempDouble / 4294967296) >>> 0 : ~~+Math.ceil((tempDouble - +(~~tempDouble >>> 0)) / 4294967296) >>> 0 : 0)], GROWABLE_HEAP_I32()[newOffset >> 2] = tempI64[0], GROWABLE_HEAP_I32()[newOffset + 4 >> 2] = tempI64[1];
    if (stream.getdents && offset === 0 && whence === 0) stream.getdents = null;
    return 0
  } catch (e) {
    if (typeof FS == "undefined" || !(e.name === "ErrnoError")) throw e;
    return e.errno
  }
}
var doWritev = (stream, iov, iovcnt, offset) => {
  var ret = 0;
  for (var i = 0; i < iovcnt; i++) {
    var ptr = GROWABLE_HEAP_U32()[iov >> 2];
    var len = GROWABLE_HEAP_U32()[iov + 4 >> 2];
    iov += 8;
    var curr = FS.write(stream, GROWABLE_HEAP_I8(), ptr, len, offset);
    if (curr < 0) return -1;
    ret += curr;
    if (typeof offset !== "undefined") {
      offset += curr
    }
  }
  return ret
};

function _fd_write(fd, iov, iovcnt, pnum) {
  if (ENVIRONMENT_IS_PTHREAD) return proxyToMainThread(8, 1, fd, iov, iovcnt, pnum);
  try {
    var stream = SYSCALLS.getStreamFromFD(fd);
    var num = doWritev(stream, iov, iovcnt);
    GROWABLE_HEAP_U32()[pnum >> 2] = num;
    return 0
  } catch (e) {
    if (typeof FS == "undefined" || !(e.name === "ErrnoError")) throw e;
    return e.errno
  }
}

function _glClear(x0) {
  GLctx.clear(x0)
}

function _glClearColor(x0, x1, x2, x3) {
  GLctx.clearColor(x0, x1, x2, x3)
}
var isLeapYear = year => year % 4 === 0 && (year % 100 !== 0 || year % 400 === 0);
var arraySum = (array, index) => {
  var sum = 0;
  for (var i = 0; i <= index; sum += array[i++]) {}
  return sum
};
var MONTH_DAYS_LEAP = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
var MONTH_DAYS_REGULAR = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
var addDays = (date, days) => {
  var newDate = new Date(date.getTime());
  while (days > 0) {
    var leap = isLeapYear(newDate.getFullYear());
    var currentMonth = newDate.getMonth();
    var daysInCurrentMonth = (leap ? MONTH_DAYS_LEAP : MONTH_DAYS_REGULAR)[currentMonth];
    if (days > daysInCurrentMonth - newDate.getDate()) {
      days -= daysInCurrentMonth - newDate.getDate() + 1;
      newDate.setDate(1);
      if (currentMonth < 11) {
        newDate.setMonth(currentMonth + 1)
      } else {
        newDate.setMonth(0);
        newDate.setFullYear(newDate.getFullYear() + 1)
      }
    } else {
      newDate.setDate(newDate.getDate() + days);
      return newDate
    }
  }
  return newDate
};
var writeArrayToMemory = (array, buffer) => {
  GROWABLE_HEAP_I8().set(array, buffer)
};
var _strftime = (s, maxsize, format, tm) => {
  var tm_zone = GROWABLE_HEAP_U32()[tm + 40 >> 2];
  var date = {
    tm_sec: GROWABLE_HEAP_I32()[tm >> 2],
    tm_min: GROWABLE_HEAP_I32()[tm + 4 >> 2],
    tm_hour: GROWABLE_HEAP_I32()[tm + 8 >> 2],
    tm_mday: GROWABLE_HEAP_I32()[tm + 12 >> 2],
    tm_mon: GROWABLE_HEAP_I32()[tm + 16 >> 2],
    tm_year: GROWABLE_HEAP_I32()[tm + 20 >> 2],
    tm_wday: GROWABLE_HEAP_I32()[tm + 24 >> 2],
    tm_yday: GROWABLE_HEAP_I32()[tm + 28 >> 2],
    tm_isdst: GROWABLE_HEAP_I32()[tm + 32 >> 2],
    tm_gmtoff: GROWABLE_HEAP_I32()[tm + 36 >> 2],
    tm_zone: tm_zone ? UTF8ToString(tm_zone) : ""
  };
  var pattern = UTF8ToString(format);
  var EXPANSION_RULES_1 = {
    "%c": "%a %b %d %H:%M:%S %Y",
    "%D": "%m/%d/%y",
    "%F": "%Y-%m-%d",
    "%h": "%b",
    "%r": "%I:%M:%S %p",
    "%R": "%H:%M",
    "%T": "%H:%M:%S",
    "%x": "%m/%d/%y",
    "%X": "%H:%M:%S",
    "%Ec": "%c",
    "%EC": "%C",
    "%Ex": "%m/%d/%y",
    "%EX": "%H:%M:%S",
    "%Ey": "%y",
    "%EY": "%Y",
    "%Od": "%d",
    "%Oe": "%e",
    "%OH": "%H",
    "%OI": "%I",
    "%Om": "%m",
    "%OM": "%M",
    "%OS": "%S",
    "%Ou": "%u",
    "%OU": "%U",
    "%OV": "%V",
    "%Ow": "%w",
    "%OW": "%W",
    "%Oy": "%y"
  };
  for (var rule in EXPANSION_RULES_1) {
    pattern = pattern.replace(new RegExp(rule, "g"), EXPANSION_RULES_1[rule])
  }
  var WEEKDAYS = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
  var MONTHS = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];

  function leadingSomething(value, digits, character) {
    var str = typeof value == "number" ? value.toString() : value || "";
    while (str.length < digits) {
      str = character[0] + str
    }
    return str
  }

  function leadingNulls(value, digits) {
    return leadingSomething(value, digits, "0")
  }

  function compareByDay(date1, date2) {
    function sgn(value) {
      return value < 0 ? -1 : value > 0 ? 1 : 0
    }
    var compare;
    if ((compare = sgn(date1.getFullYear() - date2.getFullYear())) === 0) {
      if ((compare = sgn(date1.getMonth() - date2.getMonth())) === 0) {
        compare = sgn(date1.getDate() - date2.getDate())
      }
    }
    return compare
  }

  function getFirstWeekStartDate(janFourth) {
    switch (janFourth.getDay()) {
      case 0:
        return new Date(janFourth.getFullYear() - 1, 11, 29);
      case 1:
        return janFourth;
      case 2:
        return new Date(janFourth.getFullYear(), 0, 3);
      case 3:
        return new Date(janFourth.getFullYear(), 0, 2);
      case 4:
        return new Date(janFourth.getFullYear(), 0, 1);
      case 5:
        return new Date(janFourth.getFullYear() - 1, 11, 31);
      case 6:
        return new Date(janFourth.getFullYear() - 1, 11, 30)
    }
  }

  function getWeekBasedYear(date) {
    var thisDate = addDays(new Date(date.tm_year + 1900, 0, 1), date.tm_yday);
    var janFourthThisYear = new Date(thisDate.getFullYear(), 0, 4);
    var janFourthNextYear = new Date(thisDate.getFullYear() + 1, 0, 4);
    var firstWeekStartThisYear = getFirstWeekStartDate(janFourthThisYear);
    var firstWeekStartNextYear = getFirstWeekStartDate(janFourthNextYear);
    if (compareByDay(firstWeekStartThisYear, thisDate) <= 0) {
      if (compareByDay(firstWeekStartNextYear, thisDate) <= 0) {
        return thisDate.getFullYear() + 1
      }
      return thisDate.getFullYear()
    }
    return thisDate.getFullYear() - 1
  }
  var EXPANSION_RULES_2 = {
    "%a": date => WEEKDAYS[date.tm_wday].substring(0, 3),
    "%A": date => WEEKDAYS[date.tm_wday],
    "%b": date => MONTHS[date.tm_mon].substring(0, 3),
    "%B": date => MONTHS[date.tm_mon],
    "%C": date => {
      var year = date.tm_year + 1900;
      return leadingNulls(year / 100 | 0, 2)
    },
    "%d": date => leadingNulls(date.tm_mday, 2),
    "%e": date => leadingSomething(date.tm_mday, 2, " "),
    "%g": date => getWeekBasedYear(date).toString().substring(2),
    "%G": date => getWeekBasedYear(date),
    "%H": date => leadingNulls(date.tm_hour, 2),
    "%I": date => {
      var twelveHour = date.tm_hour;
      if (twelveHour == 0) twelveHour = 12;
      else if (twelveHour > 12) twelveHour -= 12;
      return leadingNulls(twelveHour, 2)
    },
    "%j": date => leadingNulls(date.tm_mday + arraySum(isLeapYear(date.tm_year + 1900) ? MONTH_DAYS_LEAP : MONTH_DAYS_REGULAR, date.tm_mon - 1), 3),
    "%m": date => leadingNulls(date.tm_mon + 1, 2),
    "%M": date => leadingNulls(date.tm_min, 2),
    "%n": () => "\n",
    "%p": date => {
      if (date.tm_hour >= 0 && date.tm_hour < 12) {
        return "AM"
      }
      return "PM"
    },
    "%S": date => leadingNulls(date.tm_sec, 2),
    "%t": () => "\t",
    "%u": date => date.tm_wday || 7,
    "%U": date => {
      var days = date.tm_yday + 7 - date.tm_wday;
      return leadingNulls(Math.floor(days / 7), 2)
    },
    "%V": date => {
      var val = Math.floor((date.tm_yday + 7 - (date.tm_wday + 6) % 7) / 7);
      if ((date.tm_wday + 371 - date.tm_yday - 2) % 7 <= 2) {
        val++
      }
      if (!val) {
        val = 52;
        var dec31 = (date.tm_wday + 7 - date.tm_yday - 1) % 7;
        if (dec31 == 4 || dec31 == 5 && isLeapYear(date.tm_year % 400 - 1)) {
          val++
        }
      } else if (val == 53) {
        var jan1 = (date.tm_wday + 371 - date.tm_yday) % 7;
        if (jan1 != 4 && (jan1 != 3 || !isLeapYear(date.tm_year))) val = 1
      }
      return leadingNulls(val, 2)
    },
    "%w": date => date.tm_wday,
    "%W": date => {
      var days = date.tm_yday + 7 - (date.tm_wday + 6) % 7;
      return leadingNulls(Math.floor(days / 7), 2)
    },
    "%y": date => (date.tm_year + 1900).toString().substring(2),
    "%Y": date => date.tm_year + 1900,
    "%z": date => {
      var off = date.tm_gmtoff;
      var ahead = off >= 0;
      off = Math.abs(off) / 60;
      off = off / 60 * 100 + off % 60;
      return (ahead ? "+" : "-") + String("0000" + off).slice(-4)
    },
    "%Z": date => date.tm_zone,
    "%%": () => "%"
  };
  pattern = pattern.replace(/%%/g, "\0\0");
  for (var rule in EXPANSION_RULES_2) {
    if (pattern.includes(rule)) {
      pattern = pattern.replace(new RegExp(rule, "g"), EXPANSION_RULES_2[rule](date))
    }
  }
  pattern = pattern.replace(/\0\0/g, "%");
  var bytes = intArrayFromString(pattern, false);
  if (bytes.length > maxsize) {
    return 0
  }
  writeArrayToMemory(bytes, s);
  return bytes.length - 1
};
var _strftime_l = (s, maxsize, format, tm, loc) => _strftime(s, maxsize, format, tm);
var getCFunc = ident => {
  var func = Module["_" + ident];
  return func
};
var stringToUTF8OnStack = str => {
  var size = lengthBytesUTF8(str) + 1;
  var ret = stackAlloc(size);
  stringToUTF8(str, ret, size);
  return ret
};
var ccall = (ident, returnType, argTypes, args, opts) => {
  var toC = {
    "string": str => {
      var ret = 0;
      if (str !== null && str !== undefined && str !== 0) {
        ret = stringToUTF8OnStack(str)
      }
      return ret
    },
    "array": arr => {
      var ret = stackAlloc(arr.length);
      writeArrayToMemory(arr, ret);
      return ret
    }
  };

  function convertReturnValue(ret) {
    if (returnType === "string") {
      return UTF8ToString(ret)
    }
    if (returnType === "boolean") return Boolean(ret);
    return ret
  }
  var func = getCFunc(ident);
  var cArgs = [];
  var stack = 0;
  if (args) {
    for (var i = 0; i < args.length; i++) {
      var converter = toC[argTypes[i]];
      if (converter) {
        if (stack === 0) stack = stackSave();
        cArgs[i] = converter(args[i])
      } else {
        cArgs[i] = args[i]
      }
    }
  }
  var ret = func.apply(null, cArgs);

  function onDone(ret) {
    if (stack !== 0) stackRestore(stack);
    return convertReturnValue(ret)
  }
  ret = onDone(ret);
  return ret
};
PThread.init();
var FSNode = function (parent, name, mode, rdev) {
  if (!parent) {
    parent = this
  }
  this.parent = parent;
  this.mount = parent.mount;
  this.mounted = null;
  this.id = FS.nextInode++;
  this.name = name;
  this.mode = mode;
  this.node_ops = {};
  this.stream_ops = {};
  this.rdev = rdev
};
var readMode = 292 | 73;
var writeMode = 146;
Object.defineProperties(FSNode.prototype, {
  read: {
    get: function () {
      return (this.mode & readMode) === readMode
    },
    set: function (val) {
      val ? this.mode |= readMode : this.mode &= ~readMode
    }
  },
  write: {
    get: function () {
      return (this.mode & writeMode) === writeMode
    },
    set: function (val) {
      val ? this.mode |= writeMode : this.mode &= ~writeMode
    }
  },
  isFolder: {
    get: function () {
      return FS.isDir(this.mode)
    }
  },
  isDevice: {
    get: function () {
      return FS.isChrdev(this.mode)
    }
  }
});
FS.FSNode = FSNode;
FS.createPreloadedFile = FS_createPreloadedFile;
FS.staticInit();
embind_init_charCodes();
BindingError = Module["BindingError"] = class BindingError extends Error {
  constructor(message) {
    super(message);
    this.name = "BindingError"
  }
};
InternalError = Module["InternalError"] = class InternalError extends Error {
  constructor(message) {
    super(message);
    this.name = "InternalError"
  }
};
handleAllocatorInit();
init_emval();
Module["requestFullscreen"] = (lockPointer, resizeCanvas) => Browser.requestFullscreen(lockPointer, resizeCanvas);
Module["requestAnimationFrame"] = func => Browser.requestAnimationFrame(func);
Module["setCanvasSize"] = (width, height, noUpdates) => Browser.setCanvasSize(width, height, noUpdates);
Module["pauseMainLoop"] = () => Browser.mainLoop.pause();
Module["resumeMainLoop"] = () => Browser.mainLoop.resume();
Module["getUserMedia"] = () => Browser.getUserMedia();
Module["createContext"] = (canvas, useWebGL, setInModule, webGLContextAttributes) => Browser.createContext(canvas, useWebGL, setInModule, webGLContextAttributes);
var preloadedImages = {};
var preloadedAudios = {};
var GLctx;
var proxiedFunctionTable = [_proc_exit, exitOnMainThread, setCanvasElementSizeMainThread, _environ_get, _environ_sizes_get, _fd_close, _fd_read, _fd_seek, _fd_write];
var wasmImports = {
  j: ___cxa_throw,
  F: ___emscripten_init_main_thread_js,
  s: ___emscripten_thread_cleanup,
  q: __embind_register_bigint,
  K: __embind_register_bool,
  J: __embind_register_emval,
  i: __embind_register_float,
  c: __embind_register_integer,
  b: __embind_register_memory_view,
  h: __embind_register_std_string,
  f: __embind_register_std_wstring,
  L: __embind_register_void,
  B: __emscripten_get_now_is_monotonic,
  A: __emscripten_notify_mailbox_postmessage,
  D: __emscripten_receive_on_main_thread_js,
  E: __emscripten_thread_mailbox_await,
  I: __emscripten_thread_set_strongref,
  e: _abort,
  N: _emscripten_cancel_main_loop,
  C: _emscripten_check_blocking_allowed,
  G: _emscripten_exit_with_live_runtime,
  d: _emscripten_get_now,
  z: _emscripten_resize_heap,
  y: _emscripten_set_canvas_element_size,
  m: _emscripten_set_main_loop,
  H: _emscripten_webgl_create_context,
  n: _emscripten_webgl_destroy_context,
  M: _emscripten_webgl_init_context_attributes,
  o: _emscripten_webgl_make_context_current,
  u: _environ_get,
  v: _environ_sizes_get,
  r: _exit,
  w: _fd_close,
  x: _fd_read,
  p: _fd_seek,
  g: _fd_write,
  l: _glClear,
  k: _glClearColor,
  a: wasmMemory,
  t: _strftime_l
};
var wasmExports = createWasm();
var ___wasm_call_ctors = () => (___wasm_call_ctors = wasmExports["O"])();
var _main = Module["_main"] = (a0, a1) => (_main = Module["_main"] = wasmExports["P"])(a0, a1);
var __emscripten_tls_init = Module["__emscripten_tls_init"] = () => (__emscripten_tls_init = Module["__emscripten_tls_init"] = wasmExports["R"])();
var _pthread_self = Module["_pthread_self"] = () => (_pthread_self = Module["_pthread_self"] = wasmExports["S"])();
var _malloc = a0 => (_malloc = wasmExports["T"])(a0);
var _free = a0 => (_free = wasmExports["U"])(a0);
var ___getTypeName = a0 => (___getTypeName = wasmExports["__getTypeName"])(a0);
var __embind_initialize_bindings = Module["__embind_initialize_bindings"] = () => (__embind_initialize_bindings = Module["__embind_initialize_bindings"] = wasmExports["V"])();
var __emscripten_run_callback_on_thread = (a0, a1, a2, a3, a4) => (__emscripten_run_callback_on_thread = wasmExports["_emscripten_run_callback_on_thread"])(a0, a1, a2, a3, a4);
var ___errno_location = () => (___errno_location = wasmExports["__errno_location"])();
var __emscripten_thread_init = Module["__emscripten_thread_init"] = (a0, a1, a2, a3, a4, a5) => (__emscripten_thread_init = Module["__emscripten_thread_init"] = wasmExports["W"])(a0, a1, a2, a3, a4, a5);
var __emscripten_thread_crashed = Module["__emscripten_thread_crashed"] = () => (__emscripten_thread_crashed = Module["__emscripten_thread_crashed"] = wasmExports["X"])();
var _emscripten_main_thread_process_queued_calls = () => (_emscripten_main_thread_process_queued_calls = wasmExports["emscripten_main_thread_process_queued_calls"])();
var _emscripten_main_runtime_thread_id = () => (_emscripten_main_runtime_thread_id = wasmExports["emscripten_main_runtime_thread_id"])();
var __emscripten_run_on_main_thread_js = (a0, a1, a2, a3) => (__emscripten_run_on_main_thread_js = wasmExports["Y"])(a0, a1, a2, a3);
var __emscripten_thread_free_data = a0 => (__emscripten_thread_free_data = wasmExports["Z"])(a0);
var __emscripten_thread_exit = Module["__emscripten_thread_exit"] = a0 => (__emscripten_thread_exit = Module["__emscripten_thread_exit"] = wasmExports["_"])(a0);
var __emscripten_check_mailbox = Module["__emscripten_check_mailbox"] = () => (__emscripten_check_mailbox = Module["__emscripten_check_mailbox"] = wasmExports["$"])();
var _emscripten_stack_set_limits = (a0, a1) => (_emscripten_stack_set_limits = wasmExports["aa"])(a0, a1);
var stackSave = () => (stackSave = wasmExports["ba"])();
var stackRestore = a0 => (stackRestore = wasmExports["ca"])(a0);
var stackAlloc = a0 => (stackAlloc = wasmExports["da"])(a0);
var ___cxa_is_pointer_type = a0 => (___cxa_is_pointer_type = wasmExports["ea"])(a0);
Module["wasmMemory"] = wasmMemory;
Module["keepRuntimeAlive"] = keepRuntimeAlive;
Module["ccall"] = ccall;
Module["ExitStatus"] = ExitStatus;
var calledRun;
dependenciesFulfilled = function runCaller() {
  if (!calledRun) run();
  if (!calledRun) dependenciesFulfilled = runCaller
};

function callMain() {
  var entryFunction = _main;
  var argc = 0;
  var argv = 0;
  try {
    var ret = entryFunction(argc, argv);
    exitJS(ret, true);
    return ret
  } catch (e) {
    return handleException(e)
  }
}

function run() {
  if (runDependencies > 0) {
    return
  }
  if (ENVIRONMENT_IS_PTHREAD) {
    initRuntime();
    startWorker(Module);
    return
  }
  preRun();
  if (runDependencies > 0) {
    return
  }

  function doRun() {
    if (calledRun) return;
    calledRun = true;
    Module["calledRun"] = true;
    if (ABORT) return;
    initRuntime();
    preMain();
    if (Module["onRuntimeInitialized"]) Module["onRuntimeInitialized"]();
    if (shouldRunNow) callMain();
    postRun()
  }
  if (Module["setStatus"]) {
    Module["setStatus"]("Running...");
    setTimeout(function () {
      setTimeout(function () {
        Module["setStatus"]("")
      }, 1);
      doRun()
    }, 1)
  } else {
    doRun()
  }
}
if (Module["preInit"]) {
  if (typeof Module["preInit"] == "function") Module["preInit"] = [Module["preInit"]];
  while (Module["preInit"].length > 0) {
    Module["preInit"].pop()()
  }
}
var shouldRunNow = true;
if (Module["noInitialRun"]) shouldRunNow = false;
run();