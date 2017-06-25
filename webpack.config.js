/* eslint-env node */

const path = require("path");
const webpack = require("webpack");

module.exports = {
    entry: {
        "bundle": "./static/javascript/index.js"
    },
    output: {
        filename: "[name].js",
        path: path.join(__dirname, "output", "webBook")
    },
    module: {
        rules: [
            {
                test: /\.js$/,
                exclude: /node_modules/,
                use: {
                    loader: "babel-loader",
                    options: {presets: ["env"]}
                }
            }
        ]
    },
    plugins: [
        new webpack.optimize.UglifyJsPlugin({
            include: /\.min\.js$/,
            minimize: true,
            sourceMap: "source-map"
        })
    ],
    devtool: "source-map"
};
