

var objectPrototype = Object.prototype;
var toString = objectPrototype.toString;
var enumerables = true;
var enumerablesTest = { toString: 1 };
    
    
var callOverrideParent = function () {
    var method = callOverrideParent.caller.caller; 
    return method.$owner.prototype[method.$name].apply(this, arguments);
}


for (var i in enumerablesTest) {
    enumerables = null;
}

if (enumerables) {
    enumerables = ['hasOwnProperty', 'valueOf', 'isPrototypeOf', 'propertyIsEnumerable',
                   'toLocaleString', 'toString', 'constructor'];
}

export function isObject(value) {
  // http://jsperf.com/isobject4
  return value !== null && typeof value === 'object';
};

//exports.enumerables = enumerables;


export function apply(object, config, defaults) {
    if (defaults) {
        apply(object, defaults);
    }

    if (object && config && typeof config === 'object') {
        var i, j, k;

        for (i in config) {
            object[i] = config[i];
        }

        if (enumerables) {
            for (j = enumerables.length; j--;) {
                k = enumerables[j];
                if (config.hasOwnProperty(k)) {
                    object[k] = config[k];
                }
            }
        }
    }

    return object;
}

export function applyIf(object, config) {
    var property;

    if (object) {
        for (property in config) {
            if (object[property] === undefined) {
                object[property] = config[property];
            }
        }
    }
    return object;
}

export function extend(obj){
    if(typeof Object.create === 'function'){
        return Object.create(obj || {});
    }
    var F = function(){}
    F.prototype = obj;
    return new F();
}
// exports.extend = function(obj){
// return Object.create(obj || null);
// // var obj = new Object();
// // obj.prototype = obj;
// // return obj;
// }

// }(lin));


// export function isExitsFunction(funcName) {
//     try {
//         if (typeof(eval(funcName)) == "function") {
//             return true;
//         }
//     } catch(e) {}
//     return false;
// }
// //是否存在指定变量 
// export function isExitsVariable(variableName) {
//     try {
//         if (typeof(variableName) == "undefined") {
//             //alert("value is undefined"); 
//             return false;
//         } else {
//             //alert("value is true"); 
//             return true;
//         }
//     } catch(e) {}
//     return false;
// }