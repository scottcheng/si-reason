const path = require('path');
const MiniCssExtractPlugin = require('mini-css-extract-plugin');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const outputDir = path.join(__dirname, 'dist/');
const isProd = process.env.NODE_ENV === 'production';
module.exports = {
  mode: isProd ? 'production' : 'development',
  entry: './src/Main.bs.js',
  output: {
    path: outputDir,
    filename: 'bundle.js',
    publicPath: '/'
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: 'public/index.html'
    })
  ],
  module: {
    rules: [
      {
        test: /\.(scss|css)$/,
        use: [ 'style-loader', 'css-loader', 'sass-loader' ]
      },
      {
        test: /\.(woff|woff2)$/,
        use: {
          loader: 'url-loader'
        }
      }
    ]
  }
};

// const path = require('path');
// const MiniCssExtractPlugin = require("mini-css-extract-plugin");
// module.exports = {
//   mode: 'development',
//   entry: './lib/js/src/Main.bs.js',
//   output: {
//     path: path.join(__dirname, 'public'),
//     filename: 'bundle.js'
//   },
//   module: {
//     rules: [
//       {
//         test: /\.s[ac]ss$/i,
//         use: [
//           'style-loader',
//           'css-loader',
//           {
//             loader: 'sass-loader',
//             options: {
//               sourceMap: true,
//               sassOptions: {
//                 outputStyle: 'compressed'
//               }
//             }
//           }
//         ]
//       }
//     ]
//   }
// };
