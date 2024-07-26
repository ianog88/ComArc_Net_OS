# Computer Architecture and Boolean Algebra 
This repository contains a notebook of the implementation of elementary logic gates which are used to construct core computer components such as arithmetic logic units (ALU), registers and memory. The gates are implemented from scratch using python and boolean algebra. This corresponds to the learning outcomes of the modules:
- [Computer Architecture (COAR H1001)](https://www.tudublin.ie/study/modules/coar-h1001-computer-architecture/)
- [Discrete Mathematics 1 (MATH H1030)](https://www.tudublin.ie/study/modules/math-h1030-discrete-mathematics-1/)
- [Discrete Mathematics 2 (MATH H2030)](https://www.tudublin.ie/study/modules/math-h2030-discrete-mathematics-2/)

## Implementation and Testing ([Logic_Gates.ipynb](Logic_Gates.ipynb))
For ease of testing, I implemented the logic gates as python functions. Using the NAND gate's property of “functional completeness” I implemented all other logic gates as combinations of NAND gates as seen in actual hardware. I implemented all of the common elementary logic gates such as NAND, AND, OR, NOT, NOR, XOR, MUX and DEMUX.

# Networks 
I outlined my experience in computer networking in the software development repository where I describe using the TCP protocol in order to connect to the broker's servers and my justification of this choice over the alternative HTTP protocol. Although I have not included any source code specific to networking, I did not neglect this topic. A knowledge of networking is essential when building and running automated trading software as speed is a critical factor in determining the success of the system. I just could not think of any projects specific to networking to include. The relevant modules are:
- [Network Fundamentals (NETW H2003)](https://www.tudublin.ie/study/modules/netw-h2003-network-fundamentals/)
- [Network Management (NWMG H4001)](https://www.tudublin.ie/study/modules/nwmg-h4001-network-management/)
- [Routing & Switching Essentials (NETW H2004)](https://www.tudublin.ie/study/modules/netw-h2004-routing--switching-essentials/)

# Operating Systems ([basic_shell.c](basic_shell.c))
During my time spent building and running automated trading systems, I have gained hands-on experience with complex operations such as CPU affinity and low-latency networking using a kernel bypass. While I never implemented these techniques in live trading, the process gave me a strong understanding of operating systems, particularly with regards to performance optimisation and concurrency management. I have included source code for the implementation of a basic shell with that executes commands, performs input/output redirection, and piping between two commands. The relevant modules are:
- [Operating Systems Fundamentals (OPSY H1001)](https://www.tudublin.ie/study/modules/opsy-h1001-operating-systems-fundamentals/)
- [Operating Systems (OPSY H3003)](https://www.tudublin.ie/study/modules/opsy-h3003-operating-systems/)


