/*! For license information please see 30314a37.981f4c98.js.LICENSE.txt */
(window.webpackJsonp=window.webpackJsonp||[]).push([[6],{100:function(e,t,n){"use strict";n.r(t),n.d(t,"frontMatter",(function(){return s})),n.d(t,"metadata",(function(){return u})),n.d(t,"rightToc",(function(){return b})),n.d(t,"default",(function(){return d}));var a=n(1),r=n(6),l=(n(0),n(121)),i=n(127),o=n(128),c=n(124),s={id:"installation",title:"Installation",sidebar_label:"Installation"},u={id:"get-started/installation",title:"Installation",description:"import Tabs from '@theme/Tabs';",source:"@site/docs/get-started/01-installation.md",permalink:"/shunyainterfaces/docs/get-started/installation",editUrl:"https://github.com/shunyaos/shunyainterfaces/edit/master/docs/website/docs/get-started/01-installation.md",sidebar_label:"Installation",sidebar:"docs",next:{title:"Farm Datalogger",permalink:"/shunyainterfaces/docs/get-started/demo"}},b=[{value:"Pre-requisites",id:"pre-requisites",children:[]},{value:"Installing Shunya OS",id:"installing-shunya-os",children:[{value:"Step 1 : Install Etcher",id:"step-1--install-etcher",children:[]},{value:"Step 2 : Flash Shunya OS",id:"step-2--flash-shunya-os",children:[]},{value:"Step 3 :  Booting Up with Shunya OS",id:"step-3---booting-up-with-shunya-os",children:[]}]}],p={rightToc:b};function d(e){var t=e.components,n=Object(r.a)(e,["components"]);return Object(l.b)("wrapper",Object(a.a)({},p,n,{components:t,mdxType:"MDXLayout"}),Object(l.b)("p",null,"Shunya Interfaces comes pre-installed with version 0.3-Beta of Shunya OS.\nTo use shunya interfaces you need Shunya OS installed."),Object(l.b)("h2",{id:"pre-requisites"},"Pre-requisites"),Object(l.b)("ol",null,Object(l.b)("li",{parentName:"ol"},Object(l.b)("a",Object(a.a)({parentName:"li"},{href:"http://releases.shunyaos.org/interfaces-images/"}),"Shunya OS Supported boards")),Object(l.b)("li",{parentName:"ol"},"SD card reader "),Object(l.b)("li",{parentName:"ol"},"SD card "),Object(l.b)("li",{parentName:"ol"},"Laptop ")),Object(l.b)("h2",{id:"installing-shunya-os"},"Installing Shunya OS"),Object(l.b)("h3",{id:"step-1--install-etcher"},"Step 1 : Install Etcher"),Object(l.b)(i.a,{defaultValue:"nix",values:[{label:"Windows",value:"win"},{label:"Ubuntu",value:"nix"}],mdxType:"Tabs"},Object(l.b)(o.a,{value:"nix",mdxType:"TabItem"},Object(l.b)("h4",{id:"for-ubuntu-1604"},"For Ubuntu 16.04"),Object(l.b)("ol",null,Object(l.b)("li",{parentName:"ol"},"Run this command in the Terminal ")),Object(l.b)("pre",null,Object(l.b)("code",Object(a.a)({parentName:"pre"},{className:"language-bash"}),"$ sudo apt update\n$ sudo apt install balena-etcher-electron\n"))),Object(l.b)(o.a,{value:"win",mdxType:"TabItem"},Object(l.b)("h4",{id:"for-windows"},"For Windows"),Object(l.b)("ol",null,Object(l.b)("li",{parentName:"ol"},"Download ",Object(l.b)("a",Object(a.a)({parentName:"li"},{href:"https://www.balena.io/etcher/"}),"balenaEtcher")," for Windows. "),Object(l.b)("li",{parentName:"ol"},"Run balenaEtcherSetup-xxx.exe")))),Object(l.b)("h3",{id:"step-2--flash-shunya-os"},"Step 2 : Flash Shunya OS"),Object(l.b)("ol",null,Object(l.b)("li",{parentName:"ol"},"Download ",Object(l.b)("a",Object(a.a)({parentName:"li"},{href:"http://releases.shunyaos.org/interfaces-images/"}),"Shunya OS")),Object(l.b)("li",{parentName:"ol"},"Right click on the downloaded zip file."),Object(l.b)("li",{parentName:"ol"},"Click Extract here."),Object(l.b)("li",{parentName:"ol"},"Open Etcher."),Object(l.b)("li",{parentName:"ol"},"Click Select Image."),Object(l.b)("li",{parentName:"ol"},"You will find the Shunya OS ",Object(l.b)("inlineCode",{parentName:"li"},".img")," file in the folder that we had extracted earlier. "),Object(l.b)("li",{parentName:"ol"},"Select ",Object(l.b)("inlineCode",{parentName:"li"},"shunya-aaaa-image-xxxx.img")," file."),Object(l.b)("li",{parentName:"ol"},"Insert SD card."),Object(l.b)("li",{parentName:"ol"},"Click on Flash. ")),Object(l.b)("img",{alt:"Oops!, No Image to display.",src:Object(c.a)("img/install.gif")}),";",Object(l.b)("p",null,"This will start loading the SD-card with Shunya OS."),Object(l.b)("h3",{id:"step-3---booting-up-with-shunya-os"},"Step 3 :  Booting Up with Shunya OS"),Object(l.b)("ol",null,Object(l.b)("li",{parentName:"ol"},"Insert the SD card into the board "),Object(l.b)("li",{parentName:"ol"},"Connect Keyboard and Mouse to the board "),Object(l.b)("li",{parentName:"ol"},"Connect Monitor (if available ) to the board "),Object(l.b)("li",{parentName:"ol"},"Connect Power Supply ")),Object(l.b)("p",null,"The board should boot up to Shunya OS."),Object(l.b)("h4",{id:"login"},"Login"),Object(l.b)("p",null,"Login with these credentials:"),Object(l.b)("ul",null,Object(l.b)("li",{parentName:"ul"},"Username : shunya"),Object(l.b)("li",{parentName:"ul"},"Password : shunya ")))}d.isMDXComponent=!0},121:function(e,t,n){"use strict";n.d(t,"a",(function(){return b})),n.d(t,"b",(function(){return h}));var a=n(0),r=n.n(a);function l(e,t,n){return t in e?Object.defineProperty(e,t,{value:n,enumerable:!0,configurable:!0,writable:!0}):e[t]=n,e}function i(e,t){var n=Object.keys(e);if(Object.getOwnPropertySymbols){var a=Object.getOwnPropertySymbols(e);t&&(a=a.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),n.push.apply(n,a)}return n}function o(e){for(var t=1;t<arguments.length;t++){var n=null!=arguments[t]?arguments[t]:{};t%2?i(Object(n),!0).forEach((function(t){l(e,t,n[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(n)):i(Object(n)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(n,t))}))}return e}function c(e,t){if(null==e)return{};var n,a,r=function(e,t){if(null==e)return{};var n,a,r={},l=Object.keys(e);for(a=0;a<l.length;a++)n=l[a],t.indexOf(n)>=0||(r[n]=e[n]);return r}(e,t);if(Object.getOwnPropertySymbols){var l=Object.getOwnPropertySymbols(e);for(a=0;a<l.length;a++)n=l[a],t.indexOf(n)>=0||Object.prototype.propertyIsEnumerable.call(e,n)&&(r[n]=e[n])}return r}var s=r.a.createContext({}),u=function(e){var t=r.a.useContext(s),n=t;return e&&(n="function"==typeof e?e(t):o({},t,{},e)),n},b=function(e){var t=u(e.components);return r.a.createElement(s.Provider,{value:t},e.children)},p={inlineCode:"code",wrapper:function(e){var t=e.children;return r.a.createElement(r.a.Fragment,{},t)}},d=Object(a.forwardRef)((function(e,t){var n=e.components,a=e.mdxType,l=e.originalType,i=e.parentName,s=c(e,["components","mdxType","originalType","parentName"]),b=u(n),d=a,h=b["".concat(i,".").concat(d)]||b[d]||p[d]||l;return n?r.a.createElement(h,o({ref:t},s,{components:n})):r.a.createElement(h,o({ref:t},s))}));function h(e,t){var n=arguments,a=t&&t.mdxType;if("string"==typeof e||a){var l=n.length,i=new Array(l);i[0]=d;var o={};for(var c in t)hasOwnProperty.call(t,c)&&(o[c]=t[c]);o.originalType=e,o.mdxType="string"==typeof e?e:a,i[1]=o;for(var s=2;s<l;s++)i[s]=n[s];return r.a.createElement.apply(null,i)}return r.a.createElement.apply(null,n)}d.displayName="MDXCreateElement"},122:function(e,t,n){"use strict";var a=n(0),r=n(32);t.a=function(){return Object(a.useContext)(r.a)}},123:function(e,t,n){var a;!function(){"use strict";var n={}.hasOwnProperty;function r(){for(var e=[],t=0;t<arguments.length;t++){var a=arguments[t];if(a){var l=typeof a;if("string"===l||"number"===l)e.push(a);else if(Array.isArray(a)&&a.length){var i=r.apply(null,a);i&&e.push(i)}else if("object"===l)for(var o in a)n.call(a,o)&&a[o]&&e.push(o)}}return e.join(" ")}e.exports?(r.default=r,e.exports=r):void 0===(a=function(){return r}.apply(t,[]))||(e.exports=a)}()},124:function(e,t,n){"use strict";n.d(t,"a",(function(){return r}));var a=n(122);function r(e){const{siteConfig:t}=Object(a.a)(),{baseUrl:n="/"}=t||{};if(!e)return e;return/^(https?:|\/\/)/.test(e)?e:e.startsWith("/")?n+e.slice(1):n+e}},127:function(e,t,n){"use strict";var a=n(0),r=n.n(a),l=n(123),i=n.n(l),o=n(85),c=n.n(o);const s=37,u=39;t.a=function(e){const{block:t,children:n,defaultValue:l,values:o}=e,[b,p]=Object(a.useState)(l),d=[];return r.a.createElement("div",null,r.a.createElement("ul",{role:"tablist","aria-orientation":"horizontal",className:i()("tabs",{"tabs--block":t})},o.map(({value:e,label:t})=>r.a.createElement("li",{role:"tab",tabIndex:"0","aria-selected":b===e,className:i()("tab-item",c.a.tabItem,{"tab-item--active":b===e}),key:e,ref:e=>d.push(e),onKeyDown:e=>((e,t,n)=>{switch(n.keyCode){case u:((e,t)=>{const n=e.indexOf(t)+1;e[n]?e[n].focus():e[0].focus()})(e,t);break;case s:((e,t)=>{const n=e.indexOf(t)-1;e[n]?e[n].focus():e[e.length-1].focus()})(e,t)}})(d,e.target,e),onFocus:()=>p(e),onClick:()=>p(e)},t))),r.a.createElement("div",{role:"tabpanel",className:"margin-vert--md"},a.Children.toArray(n).filter(e=>e.props.value===b)[0]))}},128:function(e,t,n){"use strict";var a=n(0),r=n.n(a);t.a=function(e){return r.a.createElement("div",null,e.children)}}}]);