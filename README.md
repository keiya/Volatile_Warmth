Volatile Warmth
===============

*世界中が涙する、ありきたりなハッシュテーブル型オンメモリキャッシュサーバ。*

構想
---------------
低機能を目指したmemcachedの代替になりもしないサーバ。
ソケットはepollとかいうノンブロッキングIOを目指してるけど、なんとも複雑なLinuxシステムコールが前に立ちはだかる！
ハッシュテーブルの実装はふつうにWikipediaに書いてる実装でもいいけど、キーでバイナリツリーつくってもおもしろかったりしなかったり？
とりあえずある程度使えるように？するために適当な言語バインディング、データベースドライバを書くつもり。
永続化はいつかやってもいいね。

実装
---------------
Cのできない輩がCを取り急ぎ手続的に使ったらこうなる例。
Hashtableは連結リスト。ハッシュ関数はFNV-1a。

妄想
---------------
**Volatile** = 揮発性の **Warmth** = ぬくもり

---------------

Protocol
---------------
### Abstract
* TCP/8814
* text/plain

### Header
* 0x00 - 0x08 -> Payload Size in Hexadecimal

### Payload
#### Store the data
    SET <key> <value>
      #=> returns HEADER + [succeed:0/failed:1]

#### Restore the data
    GET <key>
      #=> returns HEADER + raw_value

#### Purge the data
    PURGE <key>
      #=> returns HEADER + purged_key_name
