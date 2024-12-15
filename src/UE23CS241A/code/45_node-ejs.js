// commonjs-example.js

exports.constant = "MY World";
exports.myadd = function add(a, b) {
    return a + b;
};
exports.mysub = function sub(a, b) {
    return a - b;
};


// es6-example.js
export default function add(a, b) {
    return a + b;
}

export function sub(a, b) {
    return a - b;
}
