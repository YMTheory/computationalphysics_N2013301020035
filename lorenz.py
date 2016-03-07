from visual import *
from visual.graph import *
from math import *

print("""
Right button drag or Ctrl-drag to rotate "camera" to view scene.
Middle button to drag or Alt-drag to zoom in or out.
  On a two-button mouse, middle is left + right.
""")
scene.title = "Lorenz differential equation"
scene.center = vector(0,0.2,0)

#gd = gdisplay(    x=0, y=0, width=600, height=150,
                  #title='theta vs. t', xtitle='t', ytitle='theta',
                  #foreground=color.black,background=color.white,
                 # xmax=200,xmin=0,ymax=10,ymin=0.1,logy=True )

lorenz = gdots ( color = color.black,size= 1.5)
lor = gdots ( color = color.black, size= 1.5)
#draw = gdots( display=gd.display, color=color.blue,size=1.5)#, logy=True)
draw = gdots( color=color.blue,size=1.5)
# Draw grid
#for x in arange(0,51,10):
  #  box(pos=(x,0,0), axis=(0,0,50), height=0.4, width=0.4, color=(0.6,0.6,0.6) )
#for z in arange(-25,26,10):
   # box(pos=(25,0,z), axis=(50,0,0), height=0.4, width=0., color=(0.6,0.6,0.6) )


#graph1 = gdisplay()
#label(display=graph1.display)


dt = 0.01
y = vector(0, 0.221, 0)
s = vector(0, 0.220, 0)
p = vector(0, 0)
g = vector(0, 0)
h = vector(0, 0)
l=9.8
q=0.5
F=1.5
omega=0.666666666666667
for t in arange(0,200,dt):
  # Integrate a funny differential equation
  
    dydt = vector(                 - 9.8/l*sin(y[1])-q*y[0]+F*sin(omega*y[2]) ,
                              y[0] +(- 9.8/l*sin(y[1])-q*y[0]+F*sin(omega*y[2]))*dt,
                                1);
   # if y[1]<=-PI:
    #    y[1]=y[1]+2*PI
     #   y = y + dydt*dt
    #elif y[1]>=PI:
     #  y[1]=y[1]-2*PI
      # y = y + dydt*dt
    #else:
     #  y = y + dydt*dt
    #p[0] = y[1]
    #p[1] = y[0]
    dsdt = vector(                 - 9.8/l*sin(s[1])-q*s[0]+F*sin(omega*s[2]) ,
                                   s[0] +(- 9.8/l*sin(s[1])-q*s[0]+F*sin(omega*s[2]))*dt,
                                   1);
    h[0] = s[2]
    h[1] = s[1]-y[1]
    if h[1]<=-pi:
        h[1]=log(abs(h[1]+2*pi))
    elif h[1]>=pi:
        h[1]=log(abs(h[1]-2*pi))
    else:
        h[1]=log(abs(h[1]))
        
    if y[1]<=-pi: 
        y[1]=y[1]+2*pi
        y = y + dydt*dt
    elif y[1]>=pi:
       y[1]=y[1]-2*pi
       y = y + dydt*dt
    else:
       y = y + dydt*dt
    p[0] = y[1]
    p[1] = y[0]
    
    if s[1]<=-pi:
        s[1]=s[1]+2*pi
        s = s + dsdt*dt
    elif s[1]>=pi:
        s[1]=s[1]-2*pi
        s = s + dsdt*dt
    else:
        s = s + dsdt*dt
    g[0] = s[1]
    g[1] = s[0]

  # Draw lines colored by speed
    #c = clip( [mag(dydt) * 0.005], 0, 1 )[0]

    lorenz.plot( pos=p, color=(0.6,0.6, 0.3))  #color=(c,0, 1-c) )
    lor.plot(pos=g, color=(0.2,0.6, 0.4))
    #draw.plot(pos=h,color=(0.5,0.5,0.5))
   # graph1.display.visible = True 
    rate( 1000 )

    #call("ffmpeg -r 20 -i img-%3d.png -vcodec libx264 -vf format=yuv420p,scale=412:412 -y movie.mp4")
    #print ("\n Movie made: movie.mp4")
