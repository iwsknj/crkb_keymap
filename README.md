# Corne cherryのkey config

## keymapを変更する手順

1. `keymap.c`やその他のファイルを編集
2. qmk_firmwareのルートに行き、`make crkbd:kenj-i`
3. ビルドが完了したら、片方を接続し`make crkbd:kenj-i:avrdude`を実行して点滅中にリセットボタン
4. 残りの片方につなぎ3と同じことをする
5. 設定完了
