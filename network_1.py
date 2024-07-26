import pyshark

file_name = 'fuzz-2006-06-26-2594.pcap'

cap = pyshark.FileCapture(file_name)

for packet in cap:
    print(f"Packet Number: {packet.number}")
    print(f"Timestamp: {packet.sniff_time}")
    print(f"Packet Length: {packet.length} bytes")
    print(f"Protocols: {packet.layers}")
    print(f"Payload: {packet.raw_mode}")
    print('-' * 50)

for packet in cap:
    if 'HTTP' in packet:
        print(f"HTTP Packet Number: {packet.number}")
        print(f"HTTP Method: {packet.http.method}")
        print(f"HTTP Host: {packet.http.host}")
        print(f"HTTP URI: {packet.http.request_uri}")
        print(f"HTTP Status Code: {packet.http.response_code}")
        print('-' * 50)

for packet in cap:
    if 'TCP' in packet:
        print(f"TCP Packet Number: {packet.number}")
        print(f"Source Port: {packet.tcp.srcport}")
        print(f"Destination Port: {packet.tcp.dstport}")
        print(f"TCP Sequence Number: {packet.tcp.seq}")
        print(f"TCP Acknowledgement Number: {packet.tcp.ack}")
        print(f"Payload: {packet.tcp.payload}")
        print('-' * 50)
