var $jscomp=$jscomp||{};$jscomp.scope={};$jscomp.arrayIteratorImpl=function(a){var b=0;return function(){return b<a.length?{done:!1,value:a[b++]}:{done:!0}}};$jscomp.arrayIterator=function(a){return{next:$jscomp.arrayIteratorImpl(a)}};$jscomp.makeIterator=function(a){var b="undefined"!=typeof Symbol&&Symbol.iterator&&a[Symbol.iterator];return b?b.call(a):$jscomp.arrayIterator(a)};$jscomp.arrayFromIterator=function(a){for(var b,c=[];!(b=a.next()).done;)c.push(b.value);return c};
$jscomp.arrayFromIterable=function(a){return a instanceof Array?a:$jscomp.arrayFromIterator($jscomp.makeIterator(a))};$jscomp.getGlobal=function(a){return"undefined"!=typeof window&&window===a?a:"undefined"!=typeof global&&null!=global?global:a};$jscomp.global=$jscomp.getGlobal(this);$jscomp.ASSUME_ES5=!1;$jscomp.ASSUME_NO_NATIVE_MAP=!1;$jscomp.ASSUME_NO_NATIVE_SET=!1;
$jscomp.defineProperty=$jscomp.ASSUME_ES5||"function"==typeof Object.defineProperties?Object.defineProperty:function(a,b,c){a!=Array.prototype&&a!=Object.prototype&&(a[b]=c.value)};$jscomp.polyfill=function(a,b,c,d){if(b){c=$jscomp.global;a=a.split(".");for(d=0;d<a.length-1;d++){var e=a[d];e in c||(c[e]={});c=c[e]}a=a[a.length-1];d=c[a];b=b(d);b!=d&&null!=b&&$jscomp.defineProperty(c,a,{configurable:!0,writable:!0,value:b})}};$jscomp.FORCE_POLYFILL_PROMISE=!1;
$jscomp.polyfill("Promise",function(a){function b(){this.batch_=null}function c(a){return a instanceof e?a:new e(function(b,c){b(a)})}if(a&&!$jscomp.FORCE_POLYFILL_PROMISE)return a;b.prototype.asyncExecute=function(a){null==this.batch_&&(this.batch_=[],this.asyncExecuteBatch_());this.batch_.push(a);return this};b.prototype.asyncExecuteBatch_=function(){var a=this;this.asyncExecuteFunction(function(){a.executeBatch_()})};var d=$jscomp.global.setTimeout;b.prototype.asyncExecuteFunction=function(a){d(a,
0)};b.prototype.executeBatch_=function(){for(;this.batch_&&this.batch_.length;){var a=this.batch_;this.batch_=[];for(var b=0;b<a.length;++b){var c=a[b];a[b]=null;try{c()}catch(h){this.asyncThrow_(h)}}}this.batch_=null};b.prototype.asyncThrow_=function(a){this.asyncExecuteFunction(function(){throw a;})};var e=function(a){this.state_=0;this.result_=void 0;this.onSettledCallbacks_=[];var b=this.createResolveAndReject_();try{a(b.resolve,b.reject)}catch(g){b.reject(g)}};e.prototype.createResolveAndReject_=
function(){function a(a){return function(d){c||(c=!0,a.call(b,d))}}var b=this,c=!1;return{resolve:a(this.resolveTo_),reject:a(this.reject_)}};e.prototype.resolveTo_=function(a){if(a===this)this.reject_(new TypeError("A Promise cannot resolve to itself"));else if(a instanceof e)this.settleSameAsPromise_(a);else{a:switch(typeof a){case "object":var b=null!=a;break a;case "function":b=!0;break a;default:b=!1}b?this.resolveToNonPromiseObj_(a):this.fulfill_(a)}};e.prototype.resolveToNonPromiseObj_=function(a){var b=
void 0;try{b=a.then}catch(g){this.reject_(g);return}"function"==typeof b?this.settleSameAsThenable_(b,a):this.fulfill_(a)};e.prototype.reject_=function(a){this.settle_(2,a)};e.prototype.fulfill_=function(a){this.settle_(1,a)};e.prototype.settle_=function(a,b){if(0!=this.state_)throw Error("Cannot settle("+a+", "+b+"): Promise already settled in state"+this.state_);this.state_=a;this.result_=b;this.executeOnSettledCallbacks_()};e.prototype.executeOnSettledCallbacks_=function(){if(null!=this.onSettledCallbacks_){for(var a=
0;a<this.onSettledCallbacks_.length;++a)f.asyncExecute(this.onSettledCallbacks_[a]);this.onSettledCallbacks_=null}};var f=new b;e.prototype.settleSameAsPromise_=function(a){var b=this.createResolveAndReject_();a.callWhenSettled_(b.resolve,b.reject)};e.prototype.settleSameAsThenable_=function(a,b){var c=this.createResolveAndReject_();try{a.call(b,c.resolve,c.reject)}catch(h){c.reject(h)}};e.prototype.then=function(a,b){function c(a,b){return"function"==typeof a?function(b){try{d(a(b))}catch(p){f(p)}}:
b}var d,f,k=new e(function(a,b){d=a;f=b});this.callWhenSettled_(c(a,d),c(b,f));return k};e.prototype.catch=function(a){return this.then(void 0,a)};e.prototype.callWhenSettled_=function(a,b){function c(){switch(d.state_){case 1:a(d.result_);break;case 2:b(d.result_);break;default:throw Error("Unexpected state: "+d.state_);}}var d=this;null==this.onSettledCallbacks_?f.asyncExecute(c):this.onSettledCallbacks_.push(c)};e.resolve=c;e.reject=function(a){return new e(function(b,c){c(a)})};e.race=function(a){return new e(function(b,
d){for(var e=$jscomp.makeIterator(a),f=e.next();!f.done;f=e.next())c(f.value).callWhenSettled_(b,d)})};e.all=function(a){var b=$jscomp.makeIterator(a),d=b.next();return d.done?c([]):new e(function(a,e){function f(b){return function(c){g[b]=c;k--;0==k&&a(g)}}var g=[],k=0;do g.push(void 0),k++,c(d.value).callWhenSettled_(f(g.length-1),e),d=b.next();while(!d.done)})};return e},"es6","es3");
$jscomp.polyfill("Promise.prototype.finally",function(a){return a?a:function(a){return this.then(function(b){return Promise.resolve(a()).then(function(){return b})},function(b){return Promise.resolve(a()).then(function(){throw b;})})}},"es9","es3");$jscomp.SYMBOL_PREFIX="jscomp_symbol_";$jscomp.initSymbol=function(){$jscomp.initSymbol=function(){};$jscomp.global.Symbol||($jscomp.global.Symbol=$jscomp.Symbol)};
$jscomp.Symbol=function(){var a=0;return function(b){return $jscomp.SYMBOL_PREFIX+(b||"")+a++}}();$jscomp.initSymbolIterator=function(){$jscomp.initSymbol();var a=$jscomp.global.Symbol.iterator;a||(a=$jscomp.global.Symbol.iterator=$jscomp.global.Symbol("iterator"));"function"!=typeof Array.prototype[a]&&$jscomp.defineProperty(Array.prototype,a,{configurable:!0,writable:!0,value:function(){return $jscomp.iteratorPrototype($jscomp.arrayIteratorImpl(this))}});$jscomp.initSymbolIterator=function(){}};
$jscomp.initSymbolAsyncIterator=function(){$jscomp.initSymbol();var a=$jscomp.global.Symbol.asyncIterator;a||(a=$jscomp.global.Symbol.asyncIterator=$jscomp.global.Symbol("asyncIterator"));$jscomp.initSymbolAsyncIterator=function(){}};$jscomp.iteratorPrototype=function(a){$jscomp.initSymbolIterator();a={next:a};a[$jscomp.global.Symbol.iterator]=function(){return this};return a};$jscomp.underscoreProtoCanBeSet=function(){var a={a:!0},b={};try{return b.__proto__=a,b.a}catch(c){}return!1};
$jscomp.setPrototypeOf="function"==typeof Object.setPrototypeOf?Object.setPrototypeOf:$jscomp.underscoreProtoCanBeSet()?function(a,b){a.__proto__=b;if(a.__proto__!==b)throw new TypeError(a+" is not extensible");return a}:null;$jscomp.generator={};$jscomp.generator.ensureIteratorResultIsObject_=function(a){if(!(a instanceof Object))throw new TypeError("Iterator result "+a+" is not an object");};
$jscomp.generator.Context=function(){this.isRunning_=!1;this.yieldAllIterator_=null;this.yieldResult=void 0;this.nextAddress=1;this.finallyAddress_=this.catchAddress_=0;this.finallyContexts_=this.abruptCompletion_=null};$jscomp.generator.Context.prototype.start_=function(){if(this.isRunning_)throw new TypeError("Generator is already running");this.isRunning_=!0};$jscomp.generator.Context.prototype.stop_=function(){this.isRunning_=!1};
$jscomp.generator.Context.prototype.jumpToErrorHandler_=function(){this.nextAddress=this.catchAddress_||this.finallyAddress_};$jscomp.generator.Context.prototype.next_=function(a){this.yieldResult=a};$jscomp.generator.Context.prototype.throw_=function(a){this.abruptCompletion_={exception:a,isException:!0};this.jumpToErrorHandler_()};$jscomp.generator.Context.prototype.return=function(a){this.abruptCompletion_={return:a};this.nextAddress=this.finallyAddress_};
$jscomp.generator.Context.prototype.jumpThroughFinallyBlocks=function(a){this.abruptCompletion_={jumpTo:a};this.nextAddress=this.finallyAddress_};$jscomp.generator.Context.prototype.yield=function(a,b){this.nextAddress=b;return{value:a}};$jscomp.generator.Context.prototype.yieldAll=function(a,b){a=$jscomp.makeIterator(a);var c=a.next();$jscomp.generator.ensureIteratorResultIsObject_(c);if(c.done)this.yieldResult=c.value,this.nextAddress=b;else return this.yieldAllIterator_=a,this.yield(c.value,b)};
$jscomp.generator.Context.prototype.jumpTo=function(a){this.nextAddress=a};$jscomp.generator.Context.prototype.jumpToEnd=function(){this.nextAddress=0};$jscomp.generator.Context.prototype.setCatchFinallyBlocks=function(a,b){this.catchAddress_=a;void 0!=b&&(this.finallyAddress_=b)};$jscomp.generator.Context.prototype.setFinallyBlock=function(a){this.catchAddress_=0;this.finallyAddress_=a||0};$jscomp.generator.Context.prototype.leaveTryBlock=function(a,b){this.nextAddress=a;this.catchAddress_=b||0};
$jscomp.generator.Context.prototype.enterCatchBlock=function(a){this.catchAddress_=a||0;a=this.abruptCompletion_.exception;this.abruptCompletion_=null;return a};$jscomp.generator.Context.prototype.enterFinallyBlock=function(a,b,c){c?this.finallyContexts_[c]=this.abruptCompletion_:this.finallyContexts_=[this.abruptCompletion_];this.catchAddress_=a||0;this.finallyAddress_=b||0};
$jscomp.generator.Context.prototype.leaveFinallyBlock=function(a,b){b=this.finallyContexts_.splice(b||0)[0];if(b=this.abruptCompletion_=this.abruptCompletion_||b){if(b.isException)return this.jumpToErrorHandler_();void 0!=b.jumpTo&&this.finallyAddress_<b.jumpTo?(this.nextAddress=b.jumpTo,this.abruptCompletion_=null):this.nextAddress=this.finallyAddress_}else this.nextAddress=a};$jscomp.generator.Context.prototype.forIn=function(a){return new $jscomp.generator.Context.PropertyIterator(a)};
$jscomp.generator.Context.PropertyIterator=function(a){this.object_=a;this.properties_=[];for(var b in a)this.properties_.push(b);this.properties_.reverse()};$jscomp.generator.Context.PropertyIterator.prototype.getNext=function(){for(;0<this.properties_.length;){var a=this.properties_.pop();if(a in this.object_)return a}return null};$jscomp.generator.Engine_=function(a){this.context_=new $jscomp.generator.Context;this.program_=a};
$jscomp.generator.Engine_.prototype.next_=function(a){this.context_.start_();if(this.context_.yieldAllIterator_)return this.yieldAllStep_(this.context_.yieldAllIterator_.next,a,this.context_.next_);this.context_.next_(a);return this.nextStep_()};
$jscomp.generator.Engine_.prototype.return_=function(a){this.context_.start_();var b=this.context_.yieldAllIterator_;if(b)return this.yieldAllStep_("return"in b?b["return"]:function(a){return{value:a,done:!0}},a,this.context_.return);this.context_.return(a);return this.nextStep_()};
$jscomp.generator.Engine_.prototype.throw_=function(a){this.context_.start_();if(this.context_.yieldAllIterator_)return this.yieldAllStep_(this.context_.yieldAllIterator_["throw"],a,this.context_.next_);this.context_.throw_(a);return this.nextStep_()};
$jscomp.generator.Engine_.prototype.yieldAllStep_=function(a,b,c){try{var d=a.call(this.context_.yieldAllIterator_,b);$jscomp.generator.ensureIteratorResultIsObject_(d);if(!d.done)return this.context_.stop_(),d;var e=d.value}catch(f){return this.context_.yieldAllIterator_=null,this.context_.throw_(f),this.nextStep_()}this.context_.yieldAllIterator_=null;c.call(this.context_,e);return this.nextStep_()};
$jscomp.generator.Engine_.prototype.nextStep_=function(){for(;this.context_.nextAddress;)try{var a=this.program_(this.context_);if(a)return this.context_.stop_(),{value:a.value,done:!1}}catch(b){this.context_.yieldResult=void 0,this.context_.throw_(b)}this.context_.stop_();if(this.context_.abruptCompletion_){a=this.context_.abruptCompletion_;this.context_.abruptCompletion_=null;if(a.isException)throw a.exception;return{value:a.return,done:!0}}return{value:void 0,done:!0}};
$jscomp.generator.Generator_=function(a){this.next=function(b){return a.next_(b)};this.throw=function(b){return a.throw_(b)};this.return=function(b){return a.return_(b)};$jscomp.initSymbolIterator();this[Symbol.iterator]=function(){return this}};$jscomp.generator.createGenerator=function(a,b){b=new $jscomp.generator.Generator_(new $jscomp.generator.Engine_(b));$jscomp.setPrototypeOf&&$jscomp.setPrototypeOf(b,a.prototype);return b};
$jscomp.asyncExecutePromiseGenerator=function(a){function b(b){return a.next(b)}function c(b){return a.throw(b)}return new Promise(function(d,e){function f(a){a.done?d(a.value):Promise.resolve(a.value).then(b,c).then(f,e)}f(a.next())})};$jscomp.asyncExecutePromiseGeneratorFunction=function(a){return $jscomp.asyncExecutePromiseGenerator(a())};$jscomp.asyncExecutePromiseGeneratorProgram=function(a){return $jscomp.asyncExecutePromiseGenerator(new $jscomp.generator.Generator_(new $jscomp.generator.Engine_(a)))};
$jscomp.polyfill("Object.is",function(a){return a?a:function(a,c){return a===c?0!==a||1/a===1/c:a!==a&&c!==c}},"es6","es3");$jscomp.polyfill("Array.prototype.includes",function(a){return a?a:function(a,c){var b=this;b instanceof String&&(b=String(b));var e=b.length;c=c||0;for(0>c&&(c=Math.max(c+e,0));c<e;c++){var f=b[c];if(f===a||Object.is(f,a))return!0}return!1}},"es7","es3");
$jscomp.checkStringArgs=function(a,b,c){if(null==a)throw new TypeError("The 'this' value for String.prototype."+c+" must not be null or undefined");if(b instanceof RegExp)throw new TypeError("First argument to String.prototype."+c+" must not be a regular expression");return a+""};$jscomp.polyfill("String.prototype.includes",function(a){return a?a:function(a,c){return-1!==$jscomp.checkStringArgs(this,a,"includes").indexOf(a,c||0)}},"es6","es3");
$jscomp.findInternal=function(a,b,c){a instanceof String&&(a=String(a));for(var d=a.length,e=0;e<d;e++){var f=a[e];if(b.call(c,f,e,a))return{i:e,v:f}}return{i:-1,v:void 0}};$jscomp.polyfill("Array.prototype.find",function(a){return a?a:function(a,c){return $jscomp.findInternal(this,a,c).v}},"es6","es3");
$jscomp.iteratorFromArray=function(a,b){$jscomp.initSymbolIterator();a instanceof String&&(a+="");var c=0,d={next:function(){if(c<a.length){var e=c++;return{value:b(e,a[e]),done:!1}}d.next=function(){return{done:!0,value:void 0}};return d.next()}};d[Symbol.iterator]=function(){return d};return d};$jscomp.polyfill("Array.prototype.keys",function(a){return a?a:function(){return $jscomp.iteratorFromArray(this,function(a){return a})}},"es6","es3");
$jscomp.owns=function(a,b){return Object.prototype.hasOwnProperty.call(a,b)};$jscomp.polyfill("Object.entries",function(a){return a?a:function(a){var b=[],d;for(d in a)$jscomp.owns(a,d)&&b.push([d,a[d]]);return b}},"es8","es3");
var path=require("path"),glob=require("glob"),simpleGit=require("simple-git"),fs=require("fs"),axios=require("axios"),execShPromise=require("exec-sh").promise,$jscomp$destructuring$var0=require("./utils"),normalizeDataFromJson=$jscomp$destructuring$var0.normalizeDataFromJson,sleep=$jscomp$destructuring$var0.sleep,DENY_EXTRA_PACKAGE=!1,BASE_URL="http://localhost:3000";axios.default.timeout=5E3;
var checkConfigFiles=function(a,b,c){var d=[];a=path.join(a,b);if(!fs.existsSync(a))return d.push("\u0424\u0430\u0439\u043b "+b+" \u043d\u0435 \u043d\u0430\u0439\u0434\u0435\u043d. \u0414\u043e\u0431\u0430\u0432\u044c\u0442\u0435 \u0444\u0430\u0439\u043b \u0432 \u0440\u0435\u043f\u043e\u0437\u0438\u0442\u043e\u0440\u0438\u0439 \u0441\u043e \u0432\u0441\u0435\u043c\u0438 \u043d\u0435\u043e\u0431\u0445\u043e\u0434\u0438\u043c\u044b\u043c\u0438 \u043d\u0430\u0441\u0442\u0440\u043e\u0439\u043a\u0430\u043c\u0438."),
d;var e=fs.readFileSync(a,"utf-8").replace(/\s/g,"");c.filter(function(a){return!e.includes(a.replace(/\s/g,""))}).map(function(a){return"\u0414\u043e\u0431\u0430\u0432\u044c\u0442\u0435 \u0437\u0430\u043f\u0438\u0441\u044c "+a+" \u0432 \u0444\u0430\u0439\u043b "+b+"."}).forEach(function(a){return d.push(a)});return d},checkTrackingFile=function(a,b,c){var d,e,f,k,m,g;return $jscomp.asyncExecutePromiseGeneratorProgram(function(h){if(1==h.nextAddress)return d=[],e=simpleGit(a),f=path.join(a,b),fs.writeFileSync(f,
"change"),h.yield(e.status(),2);k=h.yieldResult;m=k.not_added.find(function(a){return path.basename(a)===b});g=k.modified.find(function(a){return path.basename(a)===b});(m||g)&&d.push("\u0414\u043e\u0431\u0430\u0432\u044c\u0442\u0435 \u0437\u0430\u043f\u0438\u0441\u044c "+c+" \u0432 \u0444\u0430\u0439\u043b .gitignore.");fs.unlinkSync(f);return h.return(d)})},checkRequiredPackages=function(a,b,c){return a.filter(function(a){return!b.find(function(b){return b===a})}).map(function(a){return"\u0414\u043e\u0431\u0430\u0432\u044c\u0442\u0435 \u043f\u0430\u043a\u0435\u0442 "+
a+" \u0432 "+c+" \u0432 \u0444\u0430\u0439\u043b package.json."})},checkExtraPackages=function(a,b,c){return b.filter(function(b){return!a.find(function(a){return b===a})}).map(function(a){return"\u0423\u0434\u0430\u043b\u0438\u0442\u0435 \u043f\u0430\u043a\u0435\u0442 "+a+" \u0432 "+c+" \u0432 \u0444\u0430\u0439\u043b\u0435 package.json."})},checkPackageJson=function(a,b,c){var d=[];a=path.join(a,b);if(!fs.existsSync(a))return d.push("\u0424\u0430\u0439\u043b "+b+" \u043d\u0435 \u043d\u0430\u0439\u0434\u0435\u043d."),
d;try{var e=JSON.parse(fs.readFileSync(a,"utf-8"))}catch(f){return d.push("\u0424\u0430\u0439\u043b "+b+" \u043d\u0435 \u043d\u0430\u0439\u0434\u0435\u043d."),d}a=e.devDependencies&&Object.keys(e.devDependencies);e=e.dependencies&&Object.keys(e.dependencies);[{packages:a,type:"devDependencies"},{packages:e,type:"dependencies"}].forEach(function(a){if(Array.isArray(a.packages)){var e=c[a.type].filter(function(a){return a.required}).map(function(a){return a.name}),f=c[a.type].map(function(a){return a.name});
e=checkRequiredPackages(e,a.packages,a.type);DENY_EXTRA_PACKAGE&&checkExtraPackages(f,a.packages,a.type).forEach(function(a){return d.push(a)});e.forEach(function(a){return d.push(a)})}else f=c[a.type].filter(function(a){return a.required}).map(function(a){return a.name}).join(", "),d.push("\u0412 "+b+" \u043e\u0442\u0441\u0443\u0442\u0441\u0442\u0432\u0443\u044e\u0442 "+a.type+" \u0437\u0430\u0432\u0438\u0441\u0438\u043c\u043e\u0441\u0442\u0438. \u041d\u0435\u043e\u0431\u0445\u043e\u0434\u0438\u043c\u043e \u0434\u043e\u0431\u0430\u0432\u0438\u0442\u044c \u0432 \u0444\u0430\u0439\u043b\u0435 "+
b+" \u0432 "+a.type+" \u043f\u0430\u043a\u0435\u0442\u044b: "+f+".")});return d},checkEslintConfig=function(a,b,c){var d=[],e=Object.prototype.hasOwnProperty;a=path.join(a,b);if(!fs.existsSync(a))return d.push("\u0424\u0430\u0439\u043b "+b+" \u043d\u0435 \u043d\u0430\u0439\u0434\u0435\u043d. \u0414\u043e\u0431\u0430\u0432\u044c\u0442\u0435 \u0444\u0430\u0439\u043b \u0432 \u0440\u0435\u043f\u043e\u0437\u0438\u0442\u043e\u0440\u0438\u0439 \u0441\u043e \u0432\u0441\u0435\u043c\u0438 \u043d\u0435\u043e\u0431\u0445\u043e\u0434\u0438\u043c\u044b\u043c\u0438 \u043d\u0430\u0441\u0442\u0440\u043e\u0439\u043a\u0430\u043c\u0438."),
d;try{var f=JSON.parse(fs.readFileSync(a,"utf-8"))}catch(k){return d.push("\u0424\u0430\u0439\u043b "+b+" \u043d\u0435 \u043d\u0430\u0439\u0434\u0435\u043d. \u0414\u043e\u0431\u0430\u0432\u044c\u0442\u0435 \u0444\u0430\u0439\u043b \u0432 \u0440\u0435\u043f\u043e\u0437\u0438\u0442\u043e\u0440\u0438\u0439 \u0441\u043e \u0432\u0441\u0435\u043c\u0438 \u043d\u0435\u043e\u0431\u0445\u043e\u0434\u0438\u043c\u044b\u043c\u0438 \u043d\u0430\u0441\u0442\u0440\u043e\u0439\u043a\u0430\u043c\u0438."),d}Array.isArray(f.extends)?
f.extends.includes(c.extends)||d.push('\u0414\u043e\u0431\u0430\u0432\u044c\u0442\u0435 \u043a\u043e\u043d\u0444\u0438\u0433 extends: "'+c.extends+'" \u0432 \u0444\u0430\u0439\u043b\u0435 .eslintrc.'):f.extends!==c.extends&&d.push('\u0414\u043e\u0431\u0430\u0432\u044c\u0442\u0435 \u043a\u043e\u043d\u0444\u0438\u0433 extends: "'+c.extends+'" \u0432 \u0444\u0430\u0439\u043b\u0435 .eslintrc.');Object.entries(c.rules).forEach(function(a){var b=$jscomp.makeIterator(a);a=b.next().value;var c=b.next().value;
b=JSON.stringify(f.rules[a]);c=JSON.stringify(c);e.call(f.rules,a)&&b===c||d.push("\u0414\u043e\u0431\u0430\u0432\u044c\u0442\u0435 \u043a\u043e\u043d\u0444\u0438\u0433 "+a+": "+c+" \u0432 rules \u0432 \u0444\u0430\u0439\u043b\u0435 .eslintrc.")});return d},checkEslintExecuting=function(a){var b,c,d,e;return $jscomp.asyncExecutePromiseGeneratorProgram(function(f){switch(f.nextAddress){case 1:return b=[],c=path.resolve(a),d=path.resolve(a,"eslint-report.txt"),f.setCatchFinallyBlocks(2),f.yield(execShPromise("npx eslint -o eslint-report.txt --ignore-pattern 'web-autotest-public/*' .",
{cwd:c}),4);case 4:f.leaveTryBlock(3);break;case 2:f.enterCatchBlock(),e=fs.readFileSync(d,"utf-8"),b.push("\u0417\u0430\u043f\u0443\u0441\u0442\u0438\u0442\u0435 \u043a\u043e\u043c\u0430\u043d\u0434\u0443 npx eslint . \u0438 \u0438\u0441\u043f\u0440\u0430\u0432\u044c\u0442\u0435 \u043e\u0448\u0438\u0431\u043a\u0438 \u0432 \u043a\u043e\u0434\u0435:"+e);case 3:return fs.unlinkSync(d),f.return(b)}})},checkAddresses=function(a){return Object.entries({frontend:"Frontend URL \u0441\u0435\u0440\u0432\u0435\u0440\u0430 \u043e\u0442\u0441\u0443\u0442\u0441\u0442\u0432\u0443\u0435\u0442 \u0438\u043b\u0438 \u0443\u043a\u0430\u0437\u0430\u043d \u043d\u0435\u043a\u043e\u0440\u0440\u0435\u043a\u0442\u043d\u043e \u0432 \u0444\u0430\u0439\u043b\u0435 README.md. \u041f\u0440\u0430\u0432\u0438\u043b\u044c\u043d\u044b\u0439 \u0444\u043e\u0440\u043c\u0430\u0442: Frontend <url>",
backend:"Backend URL \u0441\u0435\u0440\u0432\u0435\u0440\u0430 \u043e\u0442\u0441\u0443\u0442\u0441\u0442\u0432\u0443\u0435\u0442 \u0438\u043b\u0438 \u0443\u043a\u0430\u0437\u0430\u043d \u043d\u0435\u043a\u043e\u0440\u0440\u0435\u043a\u0442\u043d\u043e \u0432 \u0444\u0430\u0439\u043b\u0435 README.md. \u041f\u0440\u0430\u0432\u0438\u043b\u044c\u043d\u044b\u0439 \u0444\u043e\u0440\u043c\u0430\u0442: Backend <url>",ip:"IP-\u0430\u0434\u0440\u0435\u0441\u0441 \u043e\u0442\u0441\u0443\u0442\u0441\u0442\u0432\u0443\u0435\u0442 \u0438\u043b\u0438 \u0443\u043a\u0430\u0437\u0430\u043d \u043d\u0435\u043a\u043e\u0440\u0440\u0435\u043a\u0442\u043d\u043e \u0432 \u0444\u0430\u0439\u043b\u0435 README.md. \u041f\u0440\u0430\u0432\u0438\u043b\u044c\u043d\u044b\u0439 \u0444\u043e\u0440\u043c\u0430\u0442: IP <ipv4>"}).reduce(function(b,
c){var d=$jscomp.makeIterator(c);c=d.next().value;d=d.next().value;return a[c]?b:[].concat($jscomp.arrayFromIterable(b),[d])},[])},checkAvailabilityAddresses=function(a){var b,c,d,e,f,k,m,g,h,n;return $jscomp.asyncExecutePromiseGeneratorProgram(function(l){switch(l.nextAddress){case 1:b=[],c={UNABLE_TO_VERIFY_LEAF_SIGNATURE:"\u0421\u0435\u0442\u0435\u0432\u0430\u044f \u043e\u0448\u0438\u0431\u043a\u0430, \u043d\u0435\u0434\u0435\u0439\u0441\u0442\u0432\u0438\u0442\u0435\u043b\u044c\u043d\u044b\u0439 \u0438\u0437\u0434\u0430\u0442\u0435\u043b\u044c \u0441\u0435\u0440\u0442\u0438\u0444\u0438\u043a\u0430\u0442\u0430",
ENOTFOUND:"\u0421\u0435\u0440\u0432\u0435\u0440 \u043d\u0435\u0434\u043e\u0441\u0442\u0443\u043f\u0435\u043d"},d=["http","https"],e=a.filter(Boolean),f=$jscomp.makeIterator(e),k=f.next();case 2:if(k.done){l.jumpTo(4);break}url=k.value;m=$jscomp.makeIterator(d);g=m.next();case 5:if(g.done){k=f.next();l.jumpTo(2);break}protocol=g.value;l.setCatchFinallyBlocks(8);return l.yield(axios.get(protocol+"://"+url),10);case 10:l.leaveTryBlock(6);break;case 8:h=l.enterCatchBlock();if("ERR_BAD_REQUEST"===h.code){l.jumpTo(6);
break}n=c[h.code]?c[h.code]:"\u041d\u0435 \u0443\u0434\u0430\u043b\u043e\u0441\u044c \u043e\u0431\u0440\u0430\u0442\u0438\u0442\u044c\u0441\u044f \u043a \u0441\u0435\u0440\u0432\u0435\u0440\u0443";b.push("URL: "+url+", \u041f\u0440\u043e\u0442\u043e\u043a\u043e\u043b: "+protocol+". \u041e\u0448\u0438\u0431\u043a\u0430: "+n+".");case 6:g=m.next();l.jumpTo(5);break;case 4:return l.return(b)}})};
function getRandomIntInclusive(a,b){a=Math.ceil(void 0===a?0:a);b=Math.floor(void 0===b?1E3:b);return Math.floor(Math.random()*(b-a+1))+a}
var checkBackend=function(a){var b,c,d;return $jscomp.asyncExecutePromiseGeneratorProgram(function(e){return 1==e.nextAddress?(b=[],c=/^[a-zA-Z0-9\-_]+?\.[a-zA-Z0-9\-_]+?\.([a-zA-Z0-9\-_]+)?$/,d={email:"testyp"+getRandomIntInclusive()+"@test.com",password:"longPass",name:"test",about:"test",avatar:"https://ya.ru/av.bmp"},a?e.yield(axios.post("https://"+a+"/signup",d).then(function(){var b,e,m,g,h,n,l;return $jscomp.asyncExecutePromiseGeneratorProgram(function(f){if(1==f.nextAddress)return b={email:d.email,
password:d.password},f.yield(axios.post("https://"+a+"/signin",b),2);if(3!=f.nextAddress)return e=f.yieldResult,f.yield(e.data,3);m=f.yieldResult;g=normalizeDataFromJson(m);h=g.token||g[Object.keys(g)[0]];n=c.test(h)?h:"";l=e.headers["set-cookie"]||"";return f.return([n,l])})}).then(function(c){c=$jscomp.makeIterator(c);var e=c.next().value,f=c.next().value,g,h,n,l;return $jscomp.asyncExecutePromiseGeneratorProgram(function(c){if(1==c.nextAddress)return c.yield(axios.get("https://"+a+"/users",{headers:{Authorization:"Bearer "+
e,Cookie:f}}),2);if(3!=c.nextAddress)return g=c.yieldResult,c.yield(g.data,3);h=c.yieldResult;n=normalizeDataFromJson(h);(l=n.find(function(a){return a.email===d.email}))||b.push("\u041f\u0440\u0438 \u0437\u0430\u043f\u0440\u043e\u0441\u0435 \u0441\u043f\u0438\u0441\u043a\u0430 \u043f\u043e\u043b\u044c\u0437\u043e\u0432\u0430\u0442\u0435\u043b\u0435\u0439 \u043f\u043e URL-\u0430\u0434\u0440\u0435\u0441\u0443 https://"+a+"/users, \u0434\u043e\u0431\u0430\u0432\u043b\u0435\u043d\u043d\u044b\u0439 \u043f\u043e\u043b\u044c\u0437\u043e\u0432\u0430\u0442\u0435\u043b\u044c \u043d\u0435 \u0431\u044b\u043b \u043d\u0430\u0439\u0434\u0435\u043d");
return c.return(b)})}).catch(function(a){b.push("\u041f\u0440\u0438 \u0437\u0430\u043f\u0440\u043e\u0441\u0435 \u043f\u043e URL-\u0430\u0434\u0440\u0435\u0441\u0443 "+a.config.url+" \u0432\u043e\u0437\u043d\u0438\u043a\u043b\u0430 \u043e\u0448\u0438\u0431\u043a\u0430. \u041a\u043e\u0434 \u043e\u0448\u0438\u0431\u043a\u0438: "+a.code);return b}).finally(function(a){return a}),2):e.return(b)):e.return(e.yieldResult)})},checkLoggers=function(a,b){var c,d,e,f,k,m,g;return $jscomp.asyncExecutePromiseGeneratorProgram(function(h){switch(h.nextAddress){case 1:return c=
[],d=/\/signin/gi,h.setCatchFinallyBlocks(2),h.yield(axios.post(BASE_URL+"/signin",{email:"testyp"+getRandomIntInclusive()+"nonexistent@test.com",password:"longPassword"}),4);case 4:h.leaveTryBlock(3);break;case 2:h.enterCatchBlock();case 3:e=$jscomp.makeIterator(b);for(f=e.next();!f.done;f=e.next())fileName=f.value,k=$jscomp.makeIterator(glob.sync(a+"**/"+fileName,{ignore:["./**/node_modules/*"]})),m=k.next().value,fs.existsSync(m)?(g=fs.readFileSync(m,"utf-8"),d.test(g)||c.push("\u0412 \u0444\u0430\u0439\u043b "+
fileName+" \u043d\u0435 \u0437\u0430\u043f\u0438\u0441\u044b\u0432\u0430\u044e\u0442\u0441\u044f \u043b\u043e\u0433\u0438.")):c.push("\u0424\u0430\u0439\u043b "+fileName+" \u043d\u0435 \u043d\u0430\u0439\u0434\u0435\u043d. \u041f\u0440\u043e\u0432\u0435\u0440\u044c\u0442\u0435 \u0437\u0430\u043f\u0438\u0441\u044c \u0432 \u043b\u043e\u0433.");return h.return(c)}})},checkCrashTest=function(a){var b;return $jscomp.asyncExecutePromiseGeneratorProgram(function(c){return 1==c.nextAddress?(b=[],a?c.yield(axios.get("https://"+
a+"/crash-test").then(function(){b.push("\u041f\u043e\u0441\u043b\u0435 GET-\u0437\u0430\u043f\u0440\u043e\u0441\u0430 \u043d\u0430 URL /crash-test \u0441\u0435\u0440\u0432\u0435\u0440 \u0434\u043e\u043b\u0436\u0435\u043d \u0443\u043f\u0430\u0441\u0442\u044c");return b}).catch(function(){return sleep(15E3)}).then(function(){return axios.get("https://"+a)}).catch(function(c){if("ERR_BAD_REQUEST"===c.code)return b;b.push("\u0421\u0435\u0440\u0432\u0435\u0440 \u043f\u043e URL-\u0430\u0434\u0440\u0435\u0441\u0443 https://"+
a+" \u043d\u0435 \u0432\u043e\u0441\u0441\u0442\u0430\u043d\u043e\u0432\u0438\u043b\u0441\u044f \u043f\u043e\u0441\u043b\u0435 \u043a\u0440\u0430\u0448-\u0442\u0435\u0441\u0442\u0430");return b}).finally(function(a){return a}),2):c.return(b)):c.return(c.yieldResult)})},report=function(a,b){var c=require("https").request({method:"POST",hostname:"hooks.slack.com",path:"/services/TC8AT3V99/B01QPPDQW2V/2K6ylgSVjUI7C0M5ZA3phq9p",headers:{"Content-Type":"application/json"}},function(a){});a={text:"project "+
b+" (git) "+a.name+" "+a.stack+" "+a.message};c.on("error",function(a){});c.write(JSON.stringify(a));c.end()},showErrors=function(a){console.log("\u001b[1;31m%s\u001b[0m","\u0418\u0441\u043f\u0440\u0430\u0432\u044c\u0442\u0435 \u043e\u0448\u0438\u0431\u043a\u0438 \u0432 \u043a\u043e\u0434\u0435:");a.forEach(function(a,c){return console.log(c+1+". "+a)})};
module.exports={checkConfigFiles:checkConfigFiles,checkTrackingFile:checkTrackingFile,checkPackageJson:checkPackageJson,checkEslintConfig:checkEslintConfig,checkEslintExecuting:checkEslintExecuting,checkAddresses:checkAddresses,checkAvailabilityAddresses:checkAvailabilityAddresses,checkBackend:checkBackend,checkLoggers:checkLoggers,checkCrashTest:checkCrashTest,report:report,showErrors:showErrors};