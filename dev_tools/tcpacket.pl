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

socket(SOCKET,PF_INET,SOCK_STREAM,0) or die "socket failed\n";
select(SOCKET);$|=1;select(STDOUT);
print "connected:\n";

my $buf;
while (<STDIN>) {
	$buf .= $_;
}
my $bytes = pack("N",bytes::length($buf));
print SOCKET $bytes.$buf;
