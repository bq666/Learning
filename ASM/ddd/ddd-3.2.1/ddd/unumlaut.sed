# $Id: unumlaut.sed,v 1.2 1997/09/19 15:33:20 zeller Exp $
# Convert 8-bit umlauts to 7-bit replacements (ae, oe, ue, ss)

s/é/e/g
s/ä/ae/g
s/ö/oe/g
s/ü/ue/g
s/ß/ss/g
s/Ä[a-z]/Ae/g
s/Ö[a-z]/Oe/g
s/Ü[a-z]/Ue/g
s/Ä/AE/g
s/Ö/OE/g
s/Ü/UE/g
