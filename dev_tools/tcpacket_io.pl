#!/usr/bin/perl

use strict;
use warnings;
use IO::Socket;
use bytes();

# test data
my $buf = 'ajsdifjalksnvzius';

my $host = $ARGV[0];
my $port = $ARGV[1];

my $sock = new IO::Socket::INET(PeerAddr=>$host,
		PeerPort=>$port,
		Proto=>'tcp');

die "IO::Socket : $!" unless $sock;

for(1 .. 2) {
  my $bytes = sprintf("%08x",bytes::length($buf));
  print $sock $bytes.$buf."\x0d\x0a";
  $sock->flush();
  print <$sock>;
}

close($sock);

