from mininet.net import Mininet
from mininet.node import OVSController
from mininet.cli import CLI
from mininet.log import setLogLevel, info
from mininet.link import TCLink
import sys
A=int(sys.argv[1])
B=int(sys.argv[2])
def createEmptyNet():
    final_hosts=[]
    final_switches=[]
    net = Mininet(controller=OVSController,link=TCLink)
    net.addController('c0')
    evenflag=1
    oddflag=1
    evenflagip='11.0.0.'
    oddflagip='11.0.1.'
    for x in range(0,B*A):
        if x%2==0:
            final_hosts.append(net.addHost('h'+str(x+1), ip=evenflagip+str(evenflag)+'/24'))
            evenflag+=1
        else:
            final_hosts.append(net.addHost('h'+str(x+1), ip=oddflagip+str(oddflag)+'/24'))
            oddflag+=1
    for x in range(0,A):
        final_switches.append(net.addSwitch('s'+str(x+1)))
    
    bwidth=0
    for x in range(0,A):
        for y in range(0,B):
            net.addLink( final_hosts[B*x+y], final_switches[x] , bw=bwidth+1)
            bwidth=(bwidth+1)%2
    for x in range(0,A-1):
        net.addLink(final_switches[x],final_switches[x+1],bw=2)

    net.start()
    CLI( net )
    net.stop()
if __name__ == '__main__':
    setLogLevel('info')
    createEmptyNet()
