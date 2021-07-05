const path = require('path');
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
