(this["webpackJsonpmini-app"]=this["webpackJsonpmini-app"]||[]).push([[0],{158:function(e,t,s){"use strict";s.r(t);var c=s(0),n=s(13),r=s.n(n),a=s(4),i=s.n(a),j=s(20),b=s(12),o=s(17),p=s.n(o),d=s(10),u=(s(156),s(1)),h=function(){var e=new XMLHttpRequest;if(e.open("GET","https://script.google.com/macros/s/AKfycbweQQLq_RF5hHRhklUHcycG4ZU1MvIRKdfsP7eKgovrjhqA-io/exec",!1),e.send(),200!=e.status)alert(e.status+": "+e.statusText);else for(var t=JSON.parse(e.responseText).result,s=[],c=0;c<t.length;c++){var n=t[c];s.push(Object(u.jsxs)("div",{children:[Object(u.jsx)("img",{src:n[1]},c),Object(u.jsx)("h1",{children:n[2]},c)]}))}return Object(u.jsxs)("div",{class:"text",children:[" ",s," "]})},l=function(e){e.id,e.fetchedUser;return Object(u.jsxs)("div",{class:"parent",children:[Object(u.jsx)(h,{}),Object(u.jsx)("iframe",{src:"https://my.spline.design/officedesktopsoundscopy-87a6594c1536b4b2cf2c810d45a9667a/",frameborder:"0",width:"100%",height:"100%"})]})},f=function(){var e=Object(c.useState)("bright_light"),t=Object(b.a)(e,2),s=t[0],n=t[1],r=Object(c.useState)("home"),a=Object(b.a)(r,2),o=a[0],h=(a[1],Object(c.useState)(null)),f=Object(b.a)(h,2),O=f[0],x=f[1],m=Object(c.useState)(null),v=Object(b.a)(m,2),g=v[0],y=v[1];return Object(c.useEffect)((function(){function e(){return(e=Object(j.a)(p.a.mark((function e(){var t;return p.a.wrap((function(e){for(;;)switch(e.prev=e.next){case 0:return e.next=2,i.a.send("VKWebAppGetUserInfo");case 2:t=e.sent,x(t),y(null);case 5:case"end":return e.stop()}}),e)})))).apply(this,arguments)}i.a.subscribe((function(e){var t=e.detail,s=t.type,c=t.data;"VKWebAppUpdateConfig"===s&&n(c.scheme)})),function(){e.apply(this,arguments)}()}),[]),Object(u.jsx)(d.c,{scheme:s,children:Object(u.jsx)(d.a,{children:Object(u.jsx)(d.b,{children:Object(u.jsx)(d.e,{popout:g,children:Object(u.jsx)(d.d,{children:Object(u.jsxs)(d.f,{activePanel:o,children:[Object(u.jsx)(l,{id:"home",fetchedUser:O}),Object(u.jsx)("div",{id:"info"})]})})})})})})};i.a.send("VKWebAppInit"),r.a.render(Object(u.jsx)(f,{}),document.getElementById("root"))}},[[158,1,2]]]);
//# sourceMappingURL=main.b8b0b870.chunk.js.map