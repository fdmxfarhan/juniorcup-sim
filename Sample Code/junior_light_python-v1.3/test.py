from juniorcup import *

r0 = Robot(0)
r1 = Robot(1)
speed = 200

def motor0(ml1, ml2, mr2, mr1):
    r0.motor(ml1 + cmp0, ml2 + cmp0, mr2 + cmp0, mr1 + cmp0)

def move0(dir):
    if(dir == 0):      motor0(speed   , speed   , -speed  , -speed   )
    if(dir == 1):      motor0(speed   , speed/2 , -speed  , -speed/2 )
    if(dir == 2):      motor0(speed   , 0       , -speed  , 0        )
    if(dir == 3):      motor0(speed   , -speed/2, -speed  , speed/2  )
    if(dir == 4):      motor0(speed   , -speed  , -speed  , speed    )
    if(dir == 5):      motor0(speed/2 , -speed  , -speed/2, speed    )
    if(dir == 6):      motor0(0       , -speed  , 0       , speed    )
    if(dir == 7):      motor0(-speed/2, -speed  , speed/2 , speed    )    
    
    if(dir == 8):      motor0(-speed  , -speed  , speed   , speed    )
    
    if(dir == 9):      motor0(-speed   , -speed/2, speed   , speed/2 )
    if(dir == 10):     motor0(-speed   , 0       , speed   , 0       )
    if(dir == 11):     motor0(-speed   , speed/2 , speed   , -speed/2)
    if(dir == 12):     motor0(-speed   , speed   , speed   , -speed  )
    if(dir == 13):     motor0(-speed/2 , speed   , speed/2 , -speed  )
    if(dir == 14):     motor0(0        , speed   , 0       , -speed  )
    if(dir == 15):     motor0(speed/2  , speed   , -speed/2, -speed  )

def motor1(ml1, ml2, mr2, mr1):
    r1.motor(ml1 + cmp1, ml2 + cmp1, mr2 + cmp1, mr1 + cmp1)

def move1(dir):
    if(dir == 0):      motor1(speed   , speed   , -speed  , -speed   )
    if(dir == 1):      motor1(speed   , speed/2 , -speed  , -speed/2 )
    if(dir == 2):      motor1(speed   , 0       , -speed  , 0        )
    if(dir == 3):      motor1(speed   , -speed/2, -speed  , speed/2  )
    if(dir == 4):      motor1(speed   , -speed  , -speed  , speed    )
    if(dir == 5):      motor1(speed/2 , -speed  , -speed/2, speed    )
    if(dir == 6):      motor1(0       , -speed  , 0       , speed    )
    if(dir == 7):      motor1(-speed/2, -speed  , speed/2 , speed    )    
    
    if(dir == 8):      motor1(-speed  , -speed  , speed   , speed    )
    
    if(dir == 9):      motor1(-speed   , -speed/2, speed   , speed/2 )
    if(dir == 10):     motor1(-speed   , 0       , speed   , 0       )
    if(dir == 11):     motor1(-speed   , speed/2 , speed   , -speed/2)
    if(dir == 12):     motor1(-speed   , speed   , speed   , -speed  )
    if(dir == 13):     motor1(-speed/2 , speed   , speed/2 , -speed  )
    if(dir == 14):     motor1(0        , speed   , 0       , -speed  )
    if(dir == 15):     motor1(speed/2  , speed   , -speed/2, -speed  )

while True:
    if 2>5 :
        print('salam')
    r0.sensor()
    cmp0 = r0.cmp
    if(cmp0 > 128): cmp0 -= 255
    cmp0 = -cmp0
    move0(r0.imin)

    r1.sensor()
    cmp1 = r1.cmp
    if(cmp1 > 128): cmp1 -= 255
    cmp1 = -cmp1
    move1(r1.imin)
    