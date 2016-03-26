from visual import*
from visual.graph import*
from math import*

scene.title="Three-Body"
scene.center=vector(0,0)

gd = gdisplay(    x=0, y=0, width=500, height=500,
                  title='orbits', xtitle='x', ytitle='y',
                  foreground=color.black,background=color.white,
                  xmax=10**12,xmin=-10**12,ymax=10**12,ymin=-10**12 )

orbit1= gdots (display=gd.display,color = color.red,size=1.5)
orbit2= gdots (display=gd.display,color = color.red,size=1.5)
orbit3= gdots (display=gd.display,color = color.red,size=0.2)

r_eo = vector (1.5*10**11-7.4*10**8,0)
r_jo = vector (7.8*10**11-7.4*10**8,0)
r_so = vector (-7.4*10**8,0)

v_eo= vector(0,30000)
v_jo= vector(0,13060)
v_so= vector(0,1)
dt=100000
Ms=2*10**30
Me=6*10**24
Mj=1.9*10**30
G=6.67*10**(-11)

for t in arange(0,4000000000,dt):
    r_es=((r_eo[0]-r_so[0])**2+(r_eo[1]-r_so[1])**2)**0.5
    r_js=((r_jo[0]-r_so[0])**2+(r_jo[1]-r_so[1])**2)**0.5
    
    rej=((r_eo[0]-r_jo[0])**2+(r_eo[1]-r_jo[1])**2)**0.5
    
    dv_eodt= vector(   -G*Ms*(r_eo[0]-r_so[0])/r_es**3-G*Mj*(r_eo[0]-r_jo[0])/rej**3,
                       -G*Ms*(r_eo[1]-r_so[1])/r_es**3-G*Mj*(r_eo[1]-r_jo[1])/rej**3);
    #print(dv_esdt)
    v_eo=v_eo+dv_eodt*dt
    #print(v_es)
    dv_jodt= vector(  -G*Ms*(r_jo[0]-r_so[0])/r_js**3-G*Mj*(r_jo[0]-r_jo[0])/rej**3,
                      -G*Ms*(r_jo[1]-r_so[1])/r_js**3-G*Mj*(r_jo[1]-r_eo[1])/rej**3);
    v_jo=v_jo+dv_jodt*dt
    dv_sodt= vector(   -G*Me*(r_so[0]-r_eo[0])/r_es**3-G*Mj*(r_so[0]-r_jo[0])/r_js**3,
                       -G*Me*(r_so[1]-r_eo[1])/r_es**3-G*Mj*(r_so[1]-r_jo[1])/r_js**3);
    
    dr_eodt= vector(    v_eo[0],
                        v_eo[1]);
    r_eo=r_eo+dr_eodt*dt
    dr_jodt= vector(    v_jo[0],
                        v_jo[1]);
    r_jo=r_jo+dr_jodt*dt
    dr_sodt= vector(    v_so[0],
                        v_so[1]);
    r_so=r_so+dr_sodt*dt
    #print(r1)
    orbit1.plot(pos=r_eo,color=(0.2,0.6,0.3))
    orbit2.plot(pos=r_jo,color=(0.4,0.3,0.5))
    #orbit3.plot(pos=r_so,color=(0.4,0.2,0.5))
