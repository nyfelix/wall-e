var path = require("path");
var config = {
   entry: {
     app: ["./app/main.js"]
   },
   output: {
     //path: path.resolve(__dirname, "build"),
     //publicPath: "./",
     path: "./",
     filename: 'index.js',
   },

   devServer: {
      inline: true,
      port: 8080
   },

   module: {
      loaders: [
         {
            test: /\.jsx?$/,
            exclude: /node_modules/,
            loader: 'babel',

            query: {
               presets: ['es2015', 'react']
            }
         }
      ]
   }
}

module.exports = config;
