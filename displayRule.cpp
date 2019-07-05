// 熊澤祐希
// ルールの表示

// fixed by Yuya Nakamura
// added #ifndef~#endif
// bug fixed (couldnt print "予習")

#ifndef DISPLAYRULE
#define DISPLAYRULE

namespace display
{
    void displayRule() {
        // printf("プレーヤーができること\n・攻撃(レポート提出、履歴書提出、論文提出)\n・低確率でクリティカルヒット\n・アイテム使用(エナジードリンク)\n・ドロップアイテムの拾得\n・スキルの使用(深呼吸 - HP回復、予\習 - 攻撃力上昇、復習 - ダメージ軽減、研究室訪問 - すばやさ上昇)\n・リキャストタイム有\n");
        cls();
        printf("概要\n\t・教授から単位を取得して卒業を目指そう\nルール\n\t・プレイヤーができること\n\t\t・攻撃(通常、レポート提出(レポート用紙を1枚消費する)、履歴書提出、論文提出)\n\t\t\t・低確率でクリティカルヒットが発生\n\t\t・アイテム使用(エナジードリンク)\n\t\t・ドロップアイテムの拾得\n\t\t・スキルの使用(リキャストタイム有)\n\t\t\t\t・戦闘が終了するとスキルのリキャストは0に戻ります\n\t\t\t・予\習: 攻撃力上昇\n\t\t\t・復習: ダメージ軽減\n\t\t\t・深呼吸: HP全回復\n\t\t\t・研究室訪問: 全スキルのリキャストを1ターン短縮\n勝利条件\n\t・ボス教授を倒す\n敗北条件\n\t・敵に倒される\n操作方法\n\t・カーソ\ル移動: A(左), W(上), D(右)\n\t・決定: Enter\n\t・メニュー: ESC\n\t・エナジードリンク使用: H\n\t・アイテム残量チェック: I\n\nPress any key to continue...\n"); // Author: 中村宥哉
        getch();
        cls();
        printf("Tips\n\t・レポート提出攻撃は知識量に応じて攻撃力が上昇します。\n\t・教授を倒すと知識量が上昇します。\n\t・教科書が落ちている部屋に入ると知識量が上昇します。\n\t・予\習スキルは積極的に使いましょう。\n\t・進級すると進級祝い金を獲得できます。\n\t・進級すると使えるスキルが増えます。\n\nPress any key to continue...\n"); // Author: 中村宥哉

    }
}

#endif