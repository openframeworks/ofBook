var tix = 0;

function init(){
    setInterval(drawDot, 10);
    setInterval(drawAim, 10);
    setInterval(step,10);
}

init();

function step(){
    tix+=.004;
}

function drawMult(){
	var c =document.getElementById("mult");
	var ctx= c.getContext("2d");
	var origin = new vec2(c.width*.25,c.height*.85);
	var zero = new vec2(0,0);
	var arrowsz = 8;

	drawGrid(ctx,origin,c.width,c.height);

	ctx.save();
	ctx.translate(origin.x,origin.y);

	ctx.font = "9pt Courier";

	ctx.lineWidth = 2;
	ctx.strokeStyle= "#bb2765";

  ctx.lineCap = "round";

	  drawVector(ctx,zero,new vec2(314,0),arrowsz,"3.14*v1 (3.14,0,0)",new vec2(0,20));
	  drawVector(ctx,zero,new vec2(0,-171),arrowsz,"1.71*v2 (0,1.71,0)",new vec2(20,0));

	  drawVector(ctx,zero,new vec2(100*3.14,-50*3.14),arrowsz,"3.14*v3 (3.14,1.57,0)",new vec2(-20,40));

  ctx.strokeStyle= "#ee3987";
	ctx.strokeStyle= "rgb(238,57,135)";

	  drawVector(ctx,zero,new vec2(100,0),arrowsz,"v1 (1,0,0)",new vec2(0,20));
	  drawVector(ctx,zero,new vec2(-100,0),arrowsz,"-1*v1 (-1,0,0)",new vec2(-10,20));
	  drawVector(ctx,zero,new vec2(0,-100),arrowsz,"v2 (0,1,0)",new vec2(20,0));
	  drawVector(ctx,zero,new vec2(100,-50),arrowsz,"v3 (1,.5,0)",new vec2(0,20));

	ctx.restore();
}

function drawAdd(){
	  var c =document.getElementById("add");
	  var ctx= c.getContext("2d");
	  var origin = new vec2(c.width*.05,c.height*.85);
	  var zero = new vec2(0,0);
	  var arrowsz = 8;

	  drawGrid(ctx,origin,c.width,c.height);

	  ctx.save();
	  ctx.translate(origin.x,origin.y);

	  ctx.font = "9pt Courier";
    ctx.lineCap = "round";

	  ctx.lineWidth = 2;
    ctx.globalAlpha = .5;
	  ctx.strokeStyle= "rgb(238,57,135)";

	  var pt4 = new vec2(314,0);
	  drawVector(ctx,zero,pt4,arrowsz,"v1 (3.14,0,0)",new vec2(0,20));

	  var pt2 = new vec2(0,-171);
	  drawVector(ctx,pt4,pt2,arrowsz,"v2 (0,1.71,0)",new vec2(10,25));
	  drawVector(ctx,zero,pt2,arrowsz,"v2 (0,1.71,0)",new vec2(10,25));
    ctx.globalAlpha = .44;
    ctx.lineWidth = 1;
    ctx.strokeStyle = "rgb(20,30,30)";
    drawVector(ctx,new vec2(0,-171*.25),new vec2(314,0),arrowsz,"move to head of v1",new vec2(-200,20));
    drawVector(ctx,new vec2(0,-171*.75),new vec2(314,0),arrowsz,"",zero);

    ctx.lineWidth = 2;
	  ctx.strokeStyle= "#bb2765";
    ctx.globalAlpha = 1.;

	  drawVector(ctx,zero,new vec2(314,-171),arrowsz,"v1 + v2 (3.14,1.71,0)", new vec2(5,-5));

	  ctx.restore();
}

function drawDiff(){
	  var c =document.getElementById("diff");
	  var ctx= c.getContext("2d");
	  var origin = new vec2(c.width*.5,c.height*.45);
	  var zero = new vec2(0,0);
	  var arrowsz = 8;

	  drawGrid(ctx,origin,c.width,c.height);

	  ctx.save();
	  ctx.translate(origin.x,origin.y);

	  ctx.font = "9pt Courier";
    ctx.lineCap = "round";

	  ctx.lineWidth = 2;
//    ctx.globalAlpha = .5;

    var scl = 4;
    var a = new vec2(31.4*scl,12.7*scl);

    var b = new vec2(12.4*scl,-8.7*scl);

	  ctx.strokeStyle= "rgb(37,208,105)";
	  ctx.fillStyle= "rgb(37,208,105)";
	  drawVector(ctx,zero,a,arrowsz,"a",new vec2(10,10));

	  ctx.strokeStyle= "rgb(57,135,238)";
	  ctx.fillStyle= "rgb(57,135,238)";
	  drawVector(ctx,zero,b,arrowsz,"b",new vec2(-15,-10));

//	  ctx.strokeStyle= "#bb2765";
//	  drawVector(ctx,a,b.minus(a),arrowsz,"a + c",new vec2(15,10));

    ctx.globalAlpha = .55;
	  ctx.fillStyle= "#177733";
	  ctx.strokeStyle= "#27bb65";
	  drawVector(ctx,b,a.times(-1),arrowsz,"b + (a*-1) = b-a",new vec2(20,0));
    ctx.globalAlpha = .35;
	  ctx.fillStyle= "#332211";
	  ctx.strokeStyle= "#997755";
	  drawVector(ctx,b,a,arrowsz,"b + a",new vec2(20,0));

    var p1 = new vec2(a.x*.25,a.y*.25);
    var p2 = new vec2(a.x*.75,a.y*.75);

	  drawVector(ctx,p1,b,arrowsz,"",zero);
	  drawVector(ctx,p2,b,arrowsz,"",zero);

    ctx.globalAlpha = 1;
	  ctx.strokeStyle= "rgb(238,57,135)";
	  ctx.fillStyle= "rgb(238,57,135)";
	  drawVector(ctx,zero,b.minus(a),arrowsz,"b + (a*-1) = b-a = c",new vec2(-150,10));

	  ctx.restore();
}


function drawAim(){
	  var c =document.getElementById("aim");
	  var ctx= c.getContext("2d");
    ctx.clearRect(0,0,c.width,c.height);
	  var origin = new vec2(c.width*.15,c.height*.425);
	  var zero = new vec2(0,0);
	  var arrowsz = 8;

	  drawGrid(ctx,origin,c.width,c.height);

	  ctx.save();
	  ctx.translate(origin.x,origin.y);

	  ctx.font = "9pt Courier";
    ctx.lineCap = "round";

	  ctx.lineWidth = 2;
//    ctx.globalAlpha = .5;

    var scl = 9;
    var a = new vec2(31.4*scl,12.7*scl);
    var b = new vec2(12.4*scl,-8.7*scl);

	  ctx.strokeStyle= "rgb(37,208,105)";
	  ctx.fillStyle= "rgb(37,208,105)";
	  drawVector(ctx,zero,a,arrowsz,"a",new vec2(10,10));

	  ctx.strokeStyle= "rgb(57,135,238)";
	  ctx.fillStyle= "rgb(57,135,238)";
	  drawVector(ctx,zero,b,arrowsz,"b",new vec2(-15,-10));

/*
    ctx.globalAlpha = 1;
	  ctx.strokeStyle= "rgb(238,57,135)";
	  ctx.fillStyle= "rgb(238,57,135)";
	  drawVector(ctx,zero,b.minus(a),arrowsz,"b + (a*-1) = b-a = c",new vec2(-150,10));
*/
    var i = 0;
    for (i = 0; i <= .6*(Math.sin(1.5*tix)+1.); i += .2){
        ctx.globalAlpha = 1;
	      ctx.strokeStyle= "rgb(238,57,135)";
	      ctx.fillStyle= "rgb(238,57,135)";
	      drawVector(ctx,a,(b.minus(a)).times(i),7,"a+"+i.toFixed(1)+"*c",new vec2(15,0));
    }

	  ctx.restore();
}

function drawNorm(){
	  var c =document.getElementById("norm");
	  var ctx= c.getContext("2d");
	  var origin = new vec2(c.width*.15,c.height*.8);
	  var zero = new vec2(0,0);
	  var arrowsz = 8;

	  drawGrid(ctx,origin,c.width,c.height);

	  ctx.save();
	  ctx.translate(origin.x,origin.y);

	  ctx.font = "9pt Courier";
    ctx.lineCap = "round";

	  ctx.lineWidth = 2;

    var scl = 9;
    var a = new vec2(31.4*scl,-12.7*scl);

	  ctx.strokeStyle= "rgb(37,208,105)";
	  ctx.fillStyle= "rgb(37,208,105)";
	  drawVector(ctx,zero,a,arrowsz,"a (length " + .01*a.length().toFixed(2) + ")",new vec2(10,10));

	  ctx.strokeStyle= "rgb(238,57,135)";
	  ctx.fillStyle= "rgb(238,57,135)";
	  drawVector(ctx,zero,a.times(100/a.length()),arrowsz,"a normalized (length 1.0)",new vec2(10,10));

	  ctx.restore();
}

function drawDot(){
	  var c =document.getElementById("dot");
	  var ctx= c.getContext("2d");
    ctx.clearRect(0,0,c.width,c.height);
	  var origin = new vec2(c.width*.5,c.height*.5);
	  var zero = new vec2(0,0);
	  var arrowsz = 8;

	  drawGrid(ctx,origin,c.width,c.height);

	  ctx.save();
	  ctx.translate(origin.x,origin.y);

	  ctx.font = "9pt Courier";
    ctx.lineCap = "round";

	  ctx.lineWidth = 2;

    var scl = 6;
    var b = new vec2(41.4*scl,-6.7*scl);
//    var aa = new vec2(18.4*scl,-13.7*scl);
    var aa = new vec2(120,0);

    var cs = Math.cos(-Math.PI/6 + (Math.PI/12)*Math.cos(tix));
    var sn = Math.sin(-Math.PI/6 + (Math.PI/12)*Math.cos(tix));

    var a = new vec2(cs*aa.x - sn*aa.y, sn*aa.x + cs*aa.y);

    var b1 = new vec2(-6.7*scl,-41.4*scl);
    b1.normalize();

	  ctx.fillStyle= "rgb(238,57,135)";

    ctx.globalAlpha = .08;
    ctx.beginPath();
    ctx.moveTo(b1.times(200.).x,b1.times(200.).y);
    ctx.lineTo(b1.times(-200.).x,b1.times(-200.).y);
    ctx.lineTo(b1.times(-200.).x + b.times(-10).x,b1.times(-200.).y + b.times(-10).y);
    ctx.lineTo(b1.times(200.).x + b.times(-10).x,b1.times(200.).y + b.times(-10).y);
    ctx.closePath();
    ctx.fill();

	  ctx.fillStyle= "rgb(37,208,105)";
    ctx.beginPath();
    ctx.moveTo(b1.times(200.).x,b1.times(200.).y);
    ctx.lineTo(b1.times(-200.).x,b1.times(-200.).y);
    ctx.lineTo(b1.times(-200.).x + b.times(10).x,b1.times(-200.).y + b.times(10).y);
    ctx.lineTo(b1.times(200.).x + b.times(10).x,b1.times(200.).y + b.times(10).y);
    ctx.closePath();
    ctx.fill();

	  ctx.fillStyle= "rgb(238,57,135)";

    ctx.globalAlpha = .9;
    ctx.fillText("dot(v,b) is negative",-220,70);
    ctx.fillText("for any v in this region",-220,95);

	  ctx.fillStyle= "rgb(37,208,105)";

    ctx.fillText("dot(v,b) is positive",120,40);
    ctx.fillText("for any v in this region",120,55);

    ctx.globalAlpha = 1;
	  ctx.strokeStyle= "rgb(37,208,105)";
	  ctx.fillStyle= "rgb(37,208,105)";
	  drawVector(ctx,zero,b,arrowsz,"b",new vec2(10,10));

    var ban = Math.atan2(b.y,b.x);
    var aan = Math.atan2(a.y,a.x);

	  ctx.fillStyle= "rgb(238,57,135)";
	  ctx.strokeStyle= "rgb(238,57,135)";

    ctx.beginPath();
    ctx.arc(0,0,60,ban,aan,true);
    ctx.stroke();

    ctx.fillText("theta", 60*Math.cos(aan)-40,60*Math.sin(aan));


    ctx.globalAlpha = .3;
	  drawVector(ctx,zero,b.times(-1),arrowsz,"-b",new vec2(-10,10));

    ctx.globalAlpha = .7;
	  ctx.strokeStyle= "rgb(57,135,238)";
	  ctx.fillStyle= "rgb(57,135,238)";
	  drawVector(ctx,zero,b1.times(100.),arrowsz,"this vector dot b = 0",new vec2(-150,0));
	  drawVector(ctx,zero,b1.times(-100.),arrowsz,"this vector dot b = 0",new vec2(10,0));

    var anorm = new vec2(a.x,a.y);
    anorm.normalize();
    var bnorm = new vec2(b.x,b.y);
    bnorm.normalize();

    ctx.globalAlpha = .8;

    var d = new vec2();
	  ctx.strokeStyle= "rgb(238,57,135)";
	  ctx.fillStyle= "rgb(238,57,135)";
    d.copy(bnorm.times(a.dot(bnorm)));
	  drawVector(ctx,zero,d,arrowsz,"d = |b|*dot(a,|b|)",new vec2(5,10));

	  ctx.strokeStyle= "rgb(57,135,238)";
	  ctx.fillStyle= "rgb(57,135,238)";
    drawVector(ctx,d,a.minus(d),arrowsz,"e = a - d",new vec2(10,5));

    ctx.globalAlpha = 1;
	  ctx.strokeStyle= "rgb(238,57,135)";
	  ctx.fillStyle= "rgb(238,57,135)";
	  drawVector(ctx,zero,a,arrowsz,"a",new vec2(-10,-10));

	  ctx.restore();
}