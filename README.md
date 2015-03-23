=======================================
Dictionatry lookup using SUN RPC
=======================================
1. Pre-requisites 
a.Install portmap using the following command:
sudo yum install rpcbind-0.2.0-11.el6.i686

2. Run the following sequence of commands to get the executable server and client program rdict and rdictd: 
cc -c rdict_clnt.c
cc -c rdict_cif.c
cc -c rdict.c
cc -c rdict_xdr.c
cc -o rdict rdict_clnt.o rdict_cif.o rdict.o rdict_xdr.o
cc -c rdict_svc.c
cc -c rdict_sif.c
cc -c rdict_srp.c
cc -o rdictd rdict_svc.o rdict_sif.o rdict_srp.o rdict_xdr.o
chmod 755 rdict
chmod 755 rdictd

3. Run the daemon first (preferably in background, this is the server)
./rdictd &

4. Run following command(this is the client):
./rdict

5. It waits for user input. Following are the possible options
        a. I                    (allows initiating the dictionary).
        b. i <word> <meaning>   (allows inserting a word, with its meaning. Example: i party a social gathering of invited guests)
        c. l <word>             (allows finding if a word is there in the dictionary. Example: l party)
        d. d <word>             (allows deleting a word from the dictionary)