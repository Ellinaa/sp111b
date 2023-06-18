# DragGAN 基於點的可控圖像合成 期中報告

# 前言
DragGAN是一種基於生成對抗網絡（GAN）的圖像合成方法，旨在提供靈活、精確和可控的圖像編輯能力。通過交互式的點操作，用戶可以準確地移動處理點到目標位置，從而實現對圖像內容的精細控制。 DragGAN的優勢在於它適用於多個對像類型，能夠精確地控製圖像的空間屬性。這使得DragGAN成為實現圖像合成和編輯的強大工具，應用於社交媒體、媒體編輯和設計等領域。

# 方法
DragGAN的操作方式是通過交互式的點操作實現圖像編輯。用戶可以點擊處理點和目標點來調整圖像中的內容。處理點表示用戶想要移動的圖像元素，目標點表示處理點需要移動到的目標位置。通過將處理點移動到目標點，用戶可以精確地控製圖像的空間屬性。

運動監督使用移動特徵補丁損失來確保處理點向目標點移動。通過優化潛在編碼，處理點朝目標點移動。 點追踪使用特徵空間中的最近鄰搜索來跟踪處理點的位置。在每次優化步驟中，處理點會向目標點靠近，最近鄰搜索保證了準確的點追踪。 通過不斷優化，直到處理點達到目標位置，DragGAN實現了用戶對圖像的精細控制。這種交互式的圖像編輯方法提供了靈活、精確和可控的圖像合成和修改能力。

# 實驗設計
DragGAN使用多個數據集來評估其性能，包括動物、人物、汽車和風景等不同對像類型。評估方法主要包括定性評估和定量評估。
定性評估通過可視化展示合成圖像的編輯效果來進行。這些展示包括對象的形變、材質合成等，可以直觀地展示DragGAN在不同對像上的編輯能力。
定量評估使用評估指標衡量DragGAN的性能。常用的指標包括結構相似性指標（SSIM）、峰值信噪比（PSNR）等，用於評估生成圖像的質量。此外，也可以使用特定任務的評估指標，如人臉識別準確率、物體檢測精度等。
    
# 實驗結果和分析
DragGAN 在不同資料集上展示了優秀的圖像編輯效果。對於動物、人物、汽車和風景等不同物體類型，DragGAN 能夠實現精確的圖像編輯，包括形變、材質合成等。

在定性比較方面，DragGAN 展示了比其他方法更靈活和精確的編輯能力。使用戶可以通過簡單的點擊操作來控制圖像內容，而無需進行複雜的手動標註或模型訓練。這使得DragGAN 在實際應用中具有較大的便利性和實用性。

在定量比較方面，DragGAN 往往能夠獲得較高的評估指標分數，與其他方法相比。例如，使用結構相似性指標（SSIM）和峰值信噪比（PSNR）等指標評估合成圖像的質量時，DragGAN 通常能夠生成更接近原始圖像的結果。此外，與其他點追踪方法相比，DragGAN 在追踪準確度方面也表現出較好的性能。

然而，DragGAN 也存在一些局限性。首先，它對初始圖像的質量和特徵表示敏感，可能受到圖像噪點或低解析度的限制。其次，DragGAN 的編輯能力受到 GAN 模型本身的限制，例如生成器和判別器的性能以及訓練資料的多樣性。此外，在處理複雜場景和形狀變換時，DragGAN 可能會面臨一些挑戰，需要進一步改進和優化。

# 應用案例
## 社交媒體圖像編輯：
![螢幕擷取畫面 2023-06-18 053741](https://github.com/Ellinaa/sp111b/assets/99786204/6f812a4f-6b3d-444f-adff-69cfa4439827)

使用者可以利用DragGAN對社交媒體上的照片進行編輯，例如改變人物或動物的位置、姿態、表情和姿勢等。這使得使用者能夠輕鬆地調整和改善他們的照片，使其更符合他們的需求和審美。

## 專業媒體編輯和電影預覽：
![螢幕擷取畫面 2023-06-18 053833](https://github.com/Ellinaa/sp111b/assets/99786204/d6e5c135-9150-4ee3-9d68-c04e423933eb)

專業媒體編輯人員和電影製片人可以利用DragGAN快速繪製出具有特定佈局的場景草圖。他們可以通過拖動操作來快速調整場景中的元素位置和佈局，以便更好地視覺化和預覽他們的創意構想。
    
## 汽車設計：
![螢幕擷取畫面 2023-06-18 053919](https://github.com/Ellinaa/sp111b/assets/99786204/85facda6-e967-41ab-aadc-c2531bb8f741)

汽車設計師可以使用DragGAN來交互式地改變他們設計的汽車形狀。他們可以通過點擊操作來調整車身的曲線和線條，實時預覽並快速生成不同版本的汽車設計。
    
通過簡單的操作實現準確的圖像編輯，而無需繁瑣的手動操作或複雜的模型訓練。他們認為DragGAN在實際應用中非常實用，能夠幫助他們快速實現自己的創意和需求。

# 執行程式
GITHUB上分享的程式[Zeqiang-Lai/DragGAN](https://github.com/Zeqiang-Lai/DragGAN)
![螢幕擷取畫面 2023-06-18 054750](https://github.com/Ellinaa/sp111b/assets/99786204/7bf20eac-158c-454b-970a-c29437d07e80)

使用裡面提供的圖片
![螢幕擷取畫面 2023-05-29 170251](https://github.com/Ellinaa/sp111b/assets/99786204/15cbf22d-9884-4d6d-aef8-cb38809a5465)

標記目標點和處理點
![螢幕擷取畫面 2023-05-29 170321](https://github.com/Ellinaa/sp111b/assets/99786204/f47daa16-816a-4095-b461-27131a2b2161)

處理到51%的變化
![螢幕擷取畫面 2023-05-29 171409](https://github.com/Ellinaa/sp111b/assets/99786204/572a898d-9579-4f29-8977-8dc819792c76)

執行完後
![螢幕擷取畫面 2023-05-29 173514](https://github.com/Ellinaa/sp111b/assets/99786204/ec6a2f22-52fd-4e11-a800-59b1c1626628)

執行過程變化[影片](https://github.com/Ellinaa/sp111b/assets/99786204/7becf6c7-34fe-4e4b-8bf2-bc4b1f1f8720)

整個介面的樣子
![screencapture-127-0-0-1-7860-1685353010458](https://github.com/Ellinaa/sp111b/assets/99786204/874caa70-d566-4104-84b3-c95a3d968ca4)

# 心得
剛開始在網路上看到這個新的GAN覺得很有趣，根本就是高級的修圖軟體，而且可以自己生成缺少的部分，使用方法也很簡單，只要把點標註好調整一下左邊介面的參數就可以了。目前官方的程式碼還沒出來只能先用GITHUB上分享的非官方程式體驗一下，但也發現了目標點跟處理點的顏色好像反過來了，文章裡是寫``` handle points (red) and target points (blue) ```。

這學期也試著使用ChatGPT幫助我寫報告，但是資訊跟資料不能太新，如圖![image](https://github.com/Ellinaa/sp111b/assets/99786204/ea81e2d5-ab57-4235-8dd3-b62231746fa8)

不然就會像我的[習題3](https://github.com/Ellinaa/sp111b/tree/main/EX/3)一樣跑出很多不相關的資料，但是整理報告的使用起來的體驗還行，希望ChatGPT還能繼續免費的使用下去。







# 參考資料
使用ChatGPT整理內容

[XingangPan/DragGAN](https://github.com/XingangPan/DragGAN)

[Zeqiang-Lai/DragGAN](https://github.com/Zeqiang-Lai/DragGAN)

[Meet Drag Your GAN: An Interactive Point-based Manipulation on the Generative Image Manifold(marktechpost)](https://www.marktechpost.com/2023/05/20/meet-drag-your-gan-an-interactive-point-based-manipulation-on-the-generative-image-manifold/)

[Drag Your GAN: Interactive Point-based Manipulation on the Generative Image Manifold(Project page)](https://vcai.mpi-inf.mpg.de/projects/DragGAN/)

[Drag Your GAN: Interactive Point-based Manipulation on the Generative Image Manifold(Paper)](https://vcai.mpi-inf.mpg.de/projects/DragGAN/data/paper.pdf)



