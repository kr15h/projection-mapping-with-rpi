# Projection Mapping with the Raspberry Pi
## Workshop at the Fab Lab Berlin on 14th and 15th May 2016 

Here you can find ofxPiMapper and its addon related version information. 

During the workshop ofxPiMapper was at commit `128271b0cf8fe2eb93b30855c109347f6c417e41`. If the examles do not compile, you might want to check out the commits used during the workshop.

1. Use openFrameworks version 0.9.3 if in trouble.

2. Clone ofxPiMapper and its dependencies (multiline copy and paste).
```
git clone https://github.com/kr15h/ofxPiMapper.git && \
git clone https://github.com/jvcleave/ofxOMXPlayer.git && \
git clone https://github.com/bakercp/ofxIO.git
```

3. Check out the appropriate commits for each of the repositories.
```
cd ofxPiMapper && git checkout 128271b0cf8fe2eb93b30855c109347f6c417e41 && cd .. && \
cd ofxOMXPlayer && git checkout 1feece5cc66389e9d9a01f73571dc80c113b23a1 && cd .. && \
cd ofxIO && git checkout f09a059cd8ce7b7a9dd72c2c2c12a56ec3b8b0eb && cd ..
```

Compile!

To return back to latest versions run the following.
```
cd ofxPiMapper && git checkout master && cd .. && \
cd ofxOMXPlayer && git checkout master && cd .. && \
cd ofxIO && git checkout master && cd ..
```