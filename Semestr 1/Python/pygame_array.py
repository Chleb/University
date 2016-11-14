#!/usr/bin/env python

import pygame
from pygame.locals import *
from sys import exit
from random import randint
from math import *
from threading import Thread
              
pygame.init()

WHITE = (255,255,255)



class ArrayThread(Thread):
   def __init__(self,N, size=600):
      Thread.__init__(self)
      self.N = N
      self.A = [N * [WHITE] for i in range(N)]
      self.B = [N * [WHITE] for i in range(N)]
      
      self.sizex = size
      self.sizey = size
      self.screen = pygame.display.set_mode((self.sizex, self.sizey))
      self.clock = pygame.time.Clock()      

      
   def run(self):
     self.DX = self.sizex / self.N
     self.DY = self.sizey / self.N
     while True:
       self.clock.tick(30)
       for event in pygame.event.get():
          if event.type == QUIT:
            exit()
       self.drawAll()
   
   def drawAll(self):
      self.screen.fill((255,255,255))
      for i in range(self.N):
        for j in range(self.N):
           if self.A[i][j] != (255,255,255):
              pygame.draw.rect(self.screen, self.A[i][j], Rect(i * self.DX, j * self.DY, self.DX, self.DY))              
      pygame.display.update() 
       
   def put(self, i, j, c):
      self.B[i][j] = c
      
   def clear(self):
      for i in range(self.N):
        for j in range(self.N):
           self.B[i][j] = WHITE
      
   def show(self):
      for i in range(self.N):
        for j in range(self.N):
           self.A[i][j] = self.B[i][j]
      self.drawAll()     
           
   def tick(self, T=30):
      self.clock.tick(T)        
   
       

