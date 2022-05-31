# MemoryGame
  + Họ và tên: Nguyễn Thị Oanh
  + MSSV: 21020373
  + Lớp môn học: INT2215 1 (nhóm 8)

## 1. Hướng dẫn cài đặt với IDE CodeBlocks: 
   + B1: Vào Command Prompt gõ: git clone https://github.com/NguyenOanhy/MemoryGame.git
   + B2: Mở file MemoryGame.cbp
   + B3: 
      - Vào Settings > Compiler > Linker settings > Other linker options: gõ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer
      - Vào Settings > Compiler > Search directories > Compiler > thêm địa chỉ chứa tệp inlude. VD: D:\MemoryGame\include
      - Vào Settings > Compiler > Search directories > Linker > thêm địa chỉ chứa tệp lib. VD: D:\MemoryGame\lib
   + B4: Nhấn biểu tượng Build and run trên màn hình
   + Hoặc: Nhấn vào mục MemoryGame.exe để chơi trực tiếp

## 2. Mô tả chung về trò chơi:
   + Game lật cặp hình giống nhau
   + Game có 8 cặp hình khác nhau tạo thành 4x4 ô hình

## 3. Mô tả các chức năng đã cài đặt:
   + Cài đặt menu với hai nút: `Play`, `Exit`.
   + Có hiệu ứng âm thanh mở đầu game
   + Khi bắt đầu chơi, các hình sẽ hiện trong một thời gian ngắn rồi ẩn đi
   + Người chơi nhấn chuột vào một cặp hình:
      - Nếu cặp hình khớp, cặp hình sẽ biến mất
      - Nếu cặp hình khớp thì ẩn cặp hình đi
   + Khi trò chơi kết thúc sẽ có hình hiện lên và có thể quay lại màn hình bắt đầu game thông qua nút `Menu`
   + Video minh họa: https://youtu.be/2lu5fMoEZW0

## 4. Các kỹ thuật lập trình được sử dụng:
   + Sử dụng mảng 1 chiều, 2 chiều, map
   + Sử dụng hàm rand() để sắp xếp các hình ngẫu nhiện
   + Sử dụng thư viện đồ họa SDL2, SDL2_image, SDL2_mixer

## 5. Kết luận và nhận xét: 
   + Game chưa thực sự hoàn thiện nhưng đã có các chức năng cơ bản. Sau khi viết xong chương trình, em cải thiện khả năng code một chút, có kiến thức nền tảng cơ bản về lập trình game và xử lý hiệu ứng...
   + Hướng phát triển:
      - Được chọn chế độ từ dễ (4x4 ô), trung bình (6x6 ô) đến khó (8x8 ô)
      - Có giới hạn thời gian cho game
      - Thêm mục tính điểm dựa vào thời gian hoàn thành game
      - Phong phú chủ đề ảnh...
   + Điểm tâm đắc:
      - Tự thiết kế hình ảnh cho game
