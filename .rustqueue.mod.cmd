savedcmd_rustqueue.mod := printf '%s\n'   rustqueue.o | awk '!x[$$0]++ { print("./"$$0) }' > rustqueue.mod
