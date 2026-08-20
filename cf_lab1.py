import time
import cflib.crtp
from cflib.crazyflie import Crazyflie
from cflib.crazyflie.syncCrazyflie import SyncCrazyflie
from cflib.positioning.motion_commander import MotionCommander


URI = 'radio:[your radio address from cfclient]'


cflib.crtp.init_drivers()


with SyncCrazyflie(URI, cf=Crazyflie(rw_cache='./cache')) as scf:
    scf.cf.platform.send_arming_request(True)   
    time.sleep(1.0)


    with MotionCommander(scf, default_height=0.5) as mc:
        time.sleep(3)        
        mc.forward(0.3)
        time.sleep(1)
        mc.back(0.3)
        time.sleep(1)
        # lands automatically
