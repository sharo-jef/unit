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
        printf("概要\n\t・教授から単位を取得して卒業を目指そう\nルール\n\t・プレイヤーができること\n\t\t・攻撃(レポート提出、履歴書提出、論文提出)\n\t\t\t・低確率でクリティカルヒットが発生\n\t\t・アイテム使用(エナジードリンク)\n\t\t・ドロップアイテムの拾得\n\t\t・スキルの使用(リキャストタイム有)\n\t\t\t・深呼吸: HP回復\n\t\t\t・予\習: 攻撃力上昇\n\t\t\t・復習: ダメージ軽減\n\t\t\t・研究室訪問: すばやさ上昇\n勝利条件\n\t・ボス教授を倒す\n敗北条件\n\t・敵に倒される\n操作方法\n\t・カーソ\ル移動: A(左), W(上), D(右)\n\t・決定: Enter\n\t・ゲーム強制終了: ESC\n");
    }
}

#endif