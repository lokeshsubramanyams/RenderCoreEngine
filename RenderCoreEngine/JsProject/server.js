const express = require('express');
const path = require('path');
const app = express();
const port = 3000; // You can use any port that Live Server is not using

app.use((req, res, next) => {
  res.setHeader('Cross-Origin-Opener-Policy', 'same-origin');
  res.setHeader('Cross-Origin-Embedder-Policy', 'require-corp');
  next();
});

app.use('/', express.static(path.join(__dirname)));

app.listen(port, () => {
  console.log(`Proxy server listening at http://localhost:${port}`);
});