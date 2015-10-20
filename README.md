# 8 Hex Generator 
This is a small program written in C++ which uses an algorithm to calculate 8-length hex keys for a given BSSID.

To compile on Windows (requires the <a href="http://www.microsoft.com/en-us/download/details.aspx?id=8279">Windows 7 SDK</a>):<br>
`cl /EHsc 8hex.cpp`

To compile on Linux:<br>
`g++ 8hex.cpp -o8hex`

##Example usage:
`8hex | oclHashcat64 -m 2500 CAP.hccap`<br>
pipes its output into <a href="http://hashcat.net/oclhashcat/">oclHashcat</a> (AMD)

`8hex | cudaHashcat64 -m 2500 CAP.hccap`<br>
pipes its output into <a href="http://hashcat.net/oclhashcat/">cudaHashcat</a> (NVIDIA)

`8hex | aircrack-ng -w - CAP.cap -e SSID`<br>
pipes its output into <a href="http://www.aircrack-ng.org/">aircrack-ng</a>

`./8hex | pyrit -r CAP.cap -i- attack_passthrough`<br>
pipes its output into <a href="https://code.google.com/p/pyrit/">pyrit</a>

## Parameters
`BSSID`<br>
Supplying a BSSID in the format of 00:11:22:33:44:55 or 001122334455 or 22:33:44:55 or 22334455 will generate all possible keys using all known algorithms. It will also calculate keys for nearby MACs (+1, +2, -1, -2) just in case the user has mistakenly entered the MAC incorrectly.
