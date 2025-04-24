ifconfig | awk '/ether/ {print $2}'
# ifconfig displays newtwork Interfaces information | awk textprocessing tool looks for 
# ether and prints the second field $2
