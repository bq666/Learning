# $Id: umlaut7.sed,v 1.2 1997/09/19 15:33:18 zeller Exp $
# Convert 8-bit umlauts to overstrike umlauts ("\"\ba" etc.)

s/�/\\o"'e"/g
s/�/\\o'"a'/g
s/�/\\o'"o'/g
s/�/\\o'"u'/g
s/�/\\o'"A'/g
s/�/\\o'"O'/g
s/�/\\o'"U'/g
s/�/\\o'ss's/g
