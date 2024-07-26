# Computer Architecture and Boolean Algebra ([Logic_Gates.ipynb](Logic_Gates.ipynb))
This repository contains a notebook of the implementation of elementary logic gates which are used to construct core computer components such as arithmetic logic units (ALU), registers and memory. The gates are implemented from scratch using python and boolean algebra. This corresponds to the learning outcomes of the modules:
- [Computer Architecture (COAR H1001)](https://www.tudublin.ie/study/modules/coar-h1001-computer-architecture/)
- [Discrete Mathematics 1 (MATH H1030)](https://www.tudublin.ie/study/modules/math-h1030-discrete-mathematics-1/)
- [Discrete Mathematics 2 (MATH H2030)](https://www.tudublin.ie/study/modules/math-h2030-discrete-mathematics-2/)

## Implementation and Testing 
For ease of testing, I implemented the logic gates as python functions. Using the NAND gate's property of “functional completeness” I implemented all other logic gates as combinations of NAND gates as seen in actual hardware. I implemented all of the common elementary logic gates such as NAND, AND, OR, NOT, NOR, XOR, MUX and DEMUX.

# Networks ([Network_1.py](Network_1.py))
Networking has a huge impact on a trading systems latency. However when studying low latency networking, I found that the majority of improvements would require upgrading hardware components such as NIC’s, switches and routers. My limited budget made this infeasible. My ability to improve performance based off the networking protocol was relatively limited in part due to the strength of Interactive Brokers platform. The biggest difference I made was changing from the default HTTP connection to TCP. This improved performance due to its persistent connection and lower overhead and was significantly more suitable for my system given the streaming nature of the price data. Interactive Brokers offer several order routes for executing trades, however they provide a smart routing option that implements dynamic routing and removes the need for you to implement it yourself. They also provide the choice between IPv4 and IPv6, in which I went for the default IPv4 as it’s the industry standard although the difference in latency between the two is insignificant. I have included a code file which uses PyShark to analyse data packets taken from the Wireshark website. Given a .pcap file it prints out basic information about each packet as well as analysing HTTP and TCP packets. This relevant modules are:
- [Network Fundamentals (NETW H2003)](https://www.tudublin.ie/study/modules/netw-h2003-network-fundamentals/)
- [Network Management (NWMG H4001)](https://www.tudublin.ie/study/modules/nwmg-h4001-network-management/)
- [Routing & Switching Essentials (NETW H2004)](https://www.tudublin.ie/study/modules/netw-h2004-routing--switching-essentials/)

# Operating Systems ([basic_shell.c](basic_shell.c))
During my time spent building and running automated trading systems, I have gained hands-on experience with complex operations such as CPU affinity and low-latency networking using a kernel bypass. While I never implemented these techniques in live trading, the process gave me a strong understanding of operating systems, particularly with regards to performance optimisation and concurrency management. I have included source code for the implementation of a basic shell with that executes commands, performs input/output redirection, and piping between two commands. The relevant modules are:
- [Operating Systems Fundamentals (OPSY H1001)](https://www.tudublin.ie/study/modules/opsy-h1001-operating-systems-fundamentals/)
- [Operating Systems (OPSY H3003)](https://www.tudublin.ie/study/modules/opsy-h3003-operating-systems/)


