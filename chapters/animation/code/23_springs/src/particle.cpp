#include "particle.h"
#include "ofMain.h"

//------------------------------------------------------------
particle::particle(){
    setInitialCondition(0,0,0,0);
    damping = 0.03f;
    bFixed = false;
}

//------------------------------------------------------------
void particle::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

//------------------------------------------------------------
void particle::addForce(float x, float y){
    // add in a fofVec2force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void particle::addRepulsionForce(float x, float y, float radius, float scale){
    // ----------- (1) make a vector of where this position is: 
    ofVec2f posOfForce;
    posOfForce.set(x,y);

    // ----------- (2) calculate the difference & length 
    ofVec2f diff	= pos - posOfForce;
    float length	= diff.length();

    // ----------- (3) check close enough
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
	  bAmCloseEnough = false;
	}
    }

    // ----------- (4) if so, update force
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);  // stronger on the inside
	diff.normalize();
	frc.x = frc.x + diff.x * scale * pct;
	frc.y = frc.y + diff.y * scale * pct;
    }
}

//------------------------------------------------------------
void particle::addAttractionForce(float x, float y, float radius, float scale){
    // ----------- (1) make a vector of where this position is: 
    ofVec2f posOfForce;
    posOfForce.set(x,y);

    // ----------- (2) calculate the difference & length 
    ofVec2f diff	= pos - posOfForce;
    float length	= diff.length();

    // ----------- (3) check close enough
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
	    bAmCloseEnough = false;
	}
    }

    // ----------- (4) if so, update force
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);  // stronger on the inside
	diff.normalize();
	frc.x = frc.x - diff.x * scale * pct;
	frc.y = frc.y - diff.y * scale * pct;
    }
}

//------------------------------------------------------------
void particle::addRepulsionForce(particle &p, float radius, float scale){
    // ----------- (1) make a vector of where this particle p is: 
    ofVec2f posOfForce;
    posOfForce.set(p.pos.x,p.pos.y);

    // ----------- (2) calculate the difference & length 
    ofVec2f diff	= pos - posOfForce;
    float length	= diff.length();

    // ----------- (3) check close enough
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
	    bAmCloseEnough = false;
	}
    }

    // ----------- (4) if so, update force
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);  // stronger on the inside
	diff.normalize();
	frc.x = frc.x + diff.x * scale * pct;
	frc.y = frc.y + diff.y * scale * pct;
	p.frc.x = p.frc.x - diff.x * scale * pct;
	p.frc.y = p.frc.y - diff.y * scale * pct;
    }
}

//------------------------------------------------------------
void particle::addAttractionForce(particle & p, float radius, float scale){
    // ----------- (1) make a vector of where this particle p is: 
    ofVec2f posOfForce;
    posOfForce.set(p.pos.x,p.pos.y);

    // ----------- (2) calculate the difference & length 
    ofVec2f diff	= pos - posOfForce;
    float length	= diff.length();

    // ----------- (3) check close enough
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
	    bAmCloseEnough = false;
	}
    }

    // ----------- (4) if so, update force
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);  // stronger on the inside
	diff.normalize();
	frc.x = frc.x - diff.x * scale * pct;
	frc.y = frc.y - diff.y * scale * pct;
	p.frc.x = p.frc.x + diff.x * scale * pct;
	p.frc.y = p.frc.y + diff.y * scale * pct;
    }
}

//------------------------------------------------------------
void particle::addClockwiseForce(particle &p, float radius, float scale){
    // ----------- (1) make a vector of where this particle p is: 
    ofVec2f posOfForce;
    posOfForce.set(p.pos.x,p.pos.y);

    // ----------- (2) calculate the difference & length 
    ofVec2f diff	= pos - posOfForce;
    float length	= diff.length();

    // ----------- (3) check close enough
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
	    bAmCloseEnough = false;
	}
    }

    // ----------- (4) if so, update force
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);  // stronger on the inside
	diff.normalize();
	frc.x = frc.x - diff.y * scale * pct;
	frc.y = frc.y + diff.x * scale * pct;
	p.frc.x = p.frc.x + diff.y * scale * pct;
	p.frc.y = p.frc.y - diff.x * scale * pct;
    }
}

//------------------------------------------------------------
void particle::addCounterClockwiseForce(particle &p, float radius, float scale){
    // ----------- (1) make a vector of where this particle p is: 
    ofVec2f posOfForce;
    posOfForce.set(p.pos.x,p.pos.y);
	
    // ----------- (2) calculate the difference & length 
    ofVec2f diff	= pos - posOfForce;
    float length	= diff.length();
	
    // ----------- (3) check close enough
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
	    bAmCloseEnough = false;
	}
    }
	
    // ----------- (4) if so, update force
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);  // stronger on the inside
	diff.normalize();
	frc.x = frc.x + diff.y * scale * pct;
	frc.y = frc.y - diff.x * scale * pct;
	p.frc.x = p.frc.x - diff.y * scale * pct;
	p.frc.y = p.frc.y + diff.x * scale * pct;
    }
}


//------------------------------------------------------------
void particle::addDampingForce(){
    // the usual way to write this is  vel *= 0.99
    // basically, subtract some part of the velocity 
    // damping is a force operating in the oposite direction of the 
    // velocity vector

    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
    vel.set(vx,vy);
}

//------------------------------------------------------------
void particle::update(){	
    if (bFixed == false){
        vel = vel + frc;
	pos = pos + vel;
    }
}

//------------------------------------------------------------
void particle::draw(){
    ofDrawCircle(pos.x, pos.y, 3);
}

//------------------------------------------------------------
void particle::bounceOffWalls(){
    // sometimes it makes sense to damped, when we hit
    bool bDampedOnCollision = true;
    bool bDidICollide = false;
	
    // what are the walls
    float minx = 0;
    float miny = 0;
    float maxx = ofGetWidth();
    float maxy = ofGetHeight();
	
    if (pos.x > maxx){
        pos.x = maxx; // move to the edge, (important!)
	vel.x *= -1;
	bDidICollide = true;
    } else if (pos.x < minx){
        pos.x = minx; // move to the edge, (important!)
	vel.x *= -1;
	bDidICollide = true;
    }

    if (pos.y > maxy){
        pos.y = maxy; // move to the edge, (important!)
	vel.y *= -1;
	bDidICollide = true;
    } else if (pos.y < miny){
        pos.y = miny; // move to the edge, (important!)
	vel.y *= -1;
	bDidICollide = true;
    }
	
    if (bDidICollide == true && bDampedOnCollision == true){
        vel *= 0.3;
    }

}
