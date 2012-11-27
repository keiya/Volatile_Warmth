#!/usr/bin/perl

use strict;
use warnings;
use Socket;
use bytes();

my $host = $ARGV[0];
my $port = $ARGV[1];

print "socket preparing\n";
my $iaddr = inet_aton($host) or die "inet_aton failed\n";
my $sock_addr = pack_sockaddr_in($port,$iaddr);

socket(SOCKET,PF_INET,SOCK_DGRAM,0) or die "socket failed\n";

my $buf;
while (<STDIN>) {
	$buf .= $_;
}
my $bytes = pack("N",bytes::length($buf));
if (send(SOCKET,$bytes.$buf,0,$sock_addr)) {
	print "sent\n";
}
