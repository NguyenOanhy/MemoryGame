# MemoryGame

1. Hướng dẫn cài đặt với IDE CodeBlocks: 
   + B1: Vào Command Prompt gõ: git clone https://github.com/NguyenOanhy/MemoryGame.git
   + B2: Mở file MemoryGame.cbp
   + B3: 
      - Vào Settings > Compiler > Linker settings > Other linker options: gõ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer
      - Vào Settings > Compiler  > Search directories > Compiler > thêm địa chỉ chứa tệp inlude. VD: D:\MemoryGame\include
      - Vào Settings > Compiler  > Search directories > Linker > thêm địa chỉ chứa tệp lib. VD: D:\MemoryGame\lib
   + B4: Nhấn biểu tượng Build and run trên màn hình
   + Hoặc: Nhấn vào mục MemoryGame.exe để chơi trực tiếp

2. Mô tả chung về trò chơi:
   + Game lật cặp hình giống nhau
   + Game có 8 cặp hình khác nhau tạo thành 4x4 ô hình


3. Mô tả các chức năng đã cài đặt:
   + Cài đặt menu với hai mục: play, exit.
   + Sắp xếp các cặp hình ngẫu nhiên
   + Khi mới bắt đầ chơi, các hình sẽ hiện trong một thời gian ngắn rồi ẩn đi
   + Người chơi nhấn chuột vào một cặp hình:
      - Nếu cặp hình khớp, cặp hình sẽ biến mất
      - Nếu cặp hình khớp thì ẩn cặp hình đi


4. Các kỹ thuật lập trình được sử dụng:
   + Sử dụng mảng 1 chiều, 2 chiều;
   + Sử dụng thư viện đồ họa SDL2, SDL2_image, SDL2_mixer;

5. Kết luận: Game chưa thực sự hoàn thiện nhưng đã có các chức năng cơ bản.
   + Hướng phát triển:
      - Được chọn chế độ từ dễ (4x4 ô), trung bình (6x6 ô) đến khó (8x8 ô)
      - Có giới hạn thời gian cho game
