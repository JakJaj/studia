#!/usr/bin/env python3
from ev3dev.ev3 import *
import math
class Robot:
    def __init__(self):
        self.radius = 2.8
        self.d = 11.8
        self.leftMotor = LargeMotor(OUTPUT_A)
        self.rightMotor = LargeMotor(OUTPUT_B)
        self.leftSensor = InfraredSensor('in3')
        self.rightSensor = InfraredSensor('in4')
        self.centralSensor = UltrasonicSensor('in2')
        self.nLeft = self.leftMotor.position
        self.nRight = self.rightMotor.position
        self.curX = 0
        self.curY = 0
        self.curPhi = 0

    def currentPosition(self): #czesc 2
        nLeft = self.leftMotor.position
        nRight = self.rightMotor.position
        
        deltaNRight = nRight - self.nRight
        deltaNLeft = nLeft - self.nLeft
        
        distanceLeft = 2 * math.pi * self.radius * (deltaNLeft / 360)
        distanceRight = 2 * math.pi * self.radius * (deltaNRight / 360)
        distanceCenter = (distanceLeft + distanceRight) / 2
        
        self.curX += distanceCenter * math.cos(self.curPhi)
        self.curY += distanceCenter * math.sin(self.curPhi)
        
        self.curPhi += (distanceRight - distanceLeft) / self.d
        
        self.nLeft = nLeft
        self.nRight = nRight
    
    def stop(self): #czesc 2
        self.leftMotor.stop()
        self.rightMotor.stop()

    def goAhead(self, predkosc, omega): #czesc 2 i czesc 3
        vRight = predkosc + omega
        vLeft = predkosc - omega
        
        self.leftMotor.run_forever(speed_sp=vLeft)
        self.rightMotor.run_forever(speed_sp=vRight)


    def distanceFromObstacle(self): #czesc 3
        distL = self.leftSensor.value() * 0.8
        
        distR = self.rightSensor.value() * 0.8
        
        distC = self.centralSensor.value() / 10
        
        return distL, distR, distC
    
    def wayClear(self): #czesc 3
        distL, distR, distC = self.distanceFromObstacle()
        if distL > 35 and distR > 35 and distC > 70:
            return True
        else:
            return False
    
    def avoidObstacle(self): #czesc 3
        distL, distR, distC = self.distanceFromObstacle()
        
        xC = distC * math.cos(self.curPhi) + 5 * math.cos(self.curPhi) + self.curX
        yC = distC * math.sin(self.curPhi) + 5 * math.sin(self.curPhi) + self.curY 
        
        xL = distL * (0.5 * math.cos(self.curPhi) - math.sqrt(3 / 2) * \
        math.sin(self.curPhi)) - 8 * math.sin(self.curPhi) + 8 * math.cos(self.curPhi) + self.curX
        
        yL = distL * (0.5 * math.sin(self.curPhi) + math.sqrt(3 / 2) * \
        math.cos(self.curPhi)) + 8 * math.sin(self.curPhi) + 8 * math.cos(self.curPhi) + self.curY
        
        xR = distR * (math.sqrt(3 / 2) * math.sin(self.curPhi) + 0.5 * \
        math.cos(self.curPhi)) - 8 * math.sin(self.curPhi) + 8 * math.cos(self.curPhi) + self.curX
        
        yR = distR * (0.5 * math.sin(self.curPhi) - math.sqrt( 3 / 2) * \
        math.cos(self.curPhi)) + 8 * math.sin(self.curPhi) + 8 * math.cos(self.curPhi) + self.curY
        
        xObst = (xC - self.curX) + (xL - self.curX) + (xR - self.curX) 
        yObst = (yC - self.curY) + (yL - self.curY) + (yR - self.curY) 
        
        return xObst, yObst
    
    def goRound(self): #czesc 3
        xObst,  yObst = self.avoidObstacle()
        distL, distR, distC = self.distanceFromObstacle()
        psi = math.atan2(yObst, xObst)
        eps = psi - self.curPhi
        Kp = 200
        predkosc = 235
        if(distL > 35 and distR > 35 and distC > 70):
            Kp = 0
        omega = Kp * eps
        self.goAhead(predkosc, omega)

    def goToGoal(self, goal): #czesc 2
        xg, yg = goal
        while (math.sqrt((xg - self.curX) ** 2 + (yg - self.curY) ** 2) > 10):
            self.currentPosition()
            psi = math.atan2(yg - self.curY, xg - self.curX)
            eps = psi - self.curPhi
            Kp = 200
            omega = Kp * eps
            predkosc = 235
            if self.wayClear():
                self.goAhead(predkosc, omega)
            else:
                self.goRound()
        self.stop()
        print(self.curX, self.curY)

goals = [[200, 0], [125, 100], [125, 200]]
r = Robot()
for goal in goals:
    r.goToGoal(goal)