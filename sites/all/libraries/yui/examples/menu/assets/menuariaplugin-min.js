(function(){var b=YAHOO.util.Event,c=YAHOO.util.Dom,k=YAHOO.lang,T=YAHOO.env.ua,Q=YAHOO.widget.ContextMenu,R=YAHOO.widget.Menu.prototype,g,J="aria-",O="haspopup",j="role",d="presentation",U="menuitem",f="href",a="submenu",G="menu",A="menubar",L="labelledby",B="itemAdded",S="trigger",M="visible",D="hidden",W="onclick",C="HTMLEvents",e="click",E="keypress";var H=function(l,m){l.setAttribute(j,m);};var I=function(l,n,m){l.setAttribute((J+n),m);};var Z=function(l){if(l.nodeType===1){I(l,O,true);}};var K=function(l){if(l.nodeType===1){l.removeAttribute(J+O);}};var F=function(m){var l=b.getTarget(m);if(c.isAncestor(this.element,l)){if(g){g.tabIndex=-1;}g=l;g.tabIndex=0;}else{if(g&&this.getItems().length>0){g.tabIndex=-1;g=c.getFirstChild(this.getItem(0).element);g.tabIndex=0;}}};var i=function(p,n){var m=n[0],q=n[1],l=b.getTarget(m),o=b.getCharCode(m);if(q&&o===13){if(T.ie){l.fireEvent(W);}else{m=document.createEvent(C);m.initEvent(e,true,true);l.dispatchEvent(m);}}};var V=function(n,m){var l=m[0];if(l){Z(c.getFirstChild(this.element));}};var P=function(n){var l=n.element;H(l.parentNode,d);H(l,d);var m=c.getFirstChild(l);H(m,U);m.tabIndex=-1;m.removeAttribute(f);if(n.cfg.getProperty(a)){Z(m);}else{n.cfg.subscribeToConfigEvent(a,V);}};var Y=function(m,l){P(l[0]);};var N=function(){I(this.element,D,!this.cfg.getProperty(M));};R.configUseARIA=function(s,r){var t=r[0],l=this.parent,n=this.element,v=(this instanceof YAHOO.widget.MenuBar)?A:G,m,q,u,o,p;if(t){H(n,v);if(l){o=c.generateId(c.getFirstChild(l.element));I(n,L,o);}m=this.getItems();q=m.length;if(q>0){p=q-1;do{u=m[p];P(u);p=p-1;}while((p>-1));if(this.getRoot()===this){g=c.getFirstChild(this.getItem(0).element);g.tabIndex=0;}}if(this===this.getRoot()){b.onFocus(document,F,null,this);}this.subscribe(B,Y);this.subscribe(E,i);this.cfg.subscribeToConfigEvent(M,N);}};var X={};var h=function(){var m=this.element.id,l=this.cfg.getProperty(S),o=X[m],n;if(o){if(k.isString(o)){n=c.get(o);if(n){K(n);}}else{if(o.nodeType===1){K(o);}else{if(o.length){c.batch(o,K);}}}}if(l){if(k.isString(l)){n=c.get(l);if(n){Z(n);}}else{if(l.nodeType===1){Z(l);}else{if(l.length){c.batch(l,Z);}}}X[m]=l;}};Q.prototype.configUseARIA=function(m,l){Q.superclass.configUseARIA.apply(this,arguments);h.call(this);this.cfg.subscribeToConfigEvent(S,h);};}());YAHOO.register("menuariaplugin",YAHOO.widget.Menu,{version:"@VERSION@",build:"@BUILD@"});YAHOO.register("menuariaplugin",YAHOO.widget.Menu,{version:"@VERSION@",build:"@BUILD@"});