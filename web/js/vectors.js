
function vec2(x,y){
  this.x = x;
  this.y = y;

  this.plus = function(v){
    return new vec2(this.x+v.x,this.y+v.y);
  }

  this.minus = function(v){
    return new vec2(this.x-v.x,this.y-v.y);
  }

  this.times = function(a){
    return new vec2(this.x*a,this.y*a);
  }
  this.dot = function(v){
   return this.x*v.x+this.y*v.y;
  }

  this.length = function(){
    return Math.sqrt(this.x*this.x + this.y*this.y);
  }

  this.normalize = function(){
      var l = this.length();
      this.x = this.x/l;
      this.y = this.y/l;
  }

    this.copy = function(v){
        this.x = v.x; this.y = v.y;
    }
}

function drawGrid(ctx, origin, wid, ht){
//lazy
var i = 0;
var j = 0;
ctx.lineWidth = 1;
ctx.strokeStyle = "#ceffe1";
for(i = origin.x; i <= wid; i+=10){
  ctx.beginPath();
  ctx.moveTo(i,0);
  ctx.lineTo(i,ht);
  ctx.stroke();
}

for(j = origin.y; j <= ht; j+=10){
  ctx.beginPath();
  ctx.moveTo(0,j);
  ctx.lineTo(wid,j);
  ctx.stroke();
}

for(i = origin.x; i > 0; i-=10){
  ctx.beginPath();
  ctx.moveTo(i,0);
  ctx.lineTo(i,ht);
  ctx.stroke();
}

for(j = origin.y; j >0; j-=10){
  ctx.beginPath();
  ctx.moveTo(0,j);
  ctx.lineTo(wid,j);
  ctx.stroke();
}

ctx.lineWidth = 2;
ctx.strokeStyle = "#aaccc1";
ctx.beginPath();
ctx.moveTo(0,origin.y);
ctx.lineTo(wid,origin.y);
ctx.stroke();

ctx.beginPath();
ctx.moveTo(origin.x,0);
ctx.lineTo(origin.x,ht);
ctx.stroke();


}

function drawVector(ctx,origin,v,arrow_len,label, labeloff){
    ctx.beginPath();
    ctx.save();
    ctx.translate(origin.x,origin.y);
    ctx.moveTo(0,0);
    ctx.lineTo(v.x,v.y);
    ctx.stroke();

    ctx.beginPath();
    var diff = new vec2(v.x*-1,v.y*-1);
    diff.normalize();
    var norm = new vec2(v.y,v.x*-1);
    norm.normalize();
    var sz = v.length() < 2*arrow_len ? v.length()*.5 : arrow_len;
    ctx.save();
    ctx.translate(v.x,v.y);
    ctx.moveTo(sz*norm.x + sz*diff.x, sz*norm.y + sz*diff.y);
    ctx.lineTo(0, 0);
    ctx.lineTo(sz*norm.x*-1 + sz*diff.x,sz*norm.y*-1 + sz*diff.y);
    ctx.stroke();
    ctx.restore();

    if(label.length){
        ctx.fillText(label,v.x+labeloff.x,v.y+labeloff.y);
    }

    ctx.restore();
}