# TetrisSDL
*Báo cáo kết quả thực hiện dự án môn Lập Trình Nâng Cao INT 2215_1 K66-UET-VNU*
## 1. Hướng dẫn cài đặt
### Thư viện SDL2 sử dụng bao gồm :
* [SDL2 ](https://www.libsdl.org/download-2.0.php)
* [SDL2_Image ](https://www.libsdl.org/projects/SDL_image/)
* [SDL2_Ttf](https://www.libsdl.org/projects/SDL_ttf/) 
* [SDL2_Mixer](https://www.libsdl.org/projects/SDL_mixer/)
### Cách cài đặt:
*Làm theo những hướng dẫn sau để cài đặt thư viện vào Visual studio code :*
* [SDL2 ](http://lazyfoo.net/tutorials/SDL/01_hello_SDL/index.php)
* [SDL2_Image](http://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/index.php) 
* SDL2_Mixer , SDL_Ttf cài đặt tương tự như SDL2_Image.
## 2. Mô tả chung:
### Ngời chơi săp xếp khối gạch để kiếm điểm tăng tiến cấp độ:
* Các khối gạch được sinh ra ngẫu nhiên và rơi xuống sau một khoảng thời gian nhất định được quy định theo từng độ khó của trò chơi.
* Khi các khối gạch lấp đầy một hàng các khối sẽ được xóa đi và cộng điểm cho người chơi.
* Với mỗi hàng được xóa đi người chơi sẽ được công điểm và khi đủ điểm cấp độ của người chơi sẽ được tăng lên.
* Trò chơi chỉ kết thúc khi có một viên gạch chạm nóc và không thể sinh ra thêm.
## 3. Mô tả các chức năng trong trò chơi:
* Menu trò chơi.
* Âm thanh nền.
* Tính điểm số.
* Tính cấp độ.
* Màn hình kết thúc trò chơi.
* Chơi lại nhiều lần.
* Các nút điều khiển cơ bản của trò chơi Tetris.
### Video minh họa sản phạm: https://youtu.be/FvEf4CBX77g;
## 4. Các kĩ thuật lập trình được sử dụng: 
* Cấu trúc.
* Lớp.
* Đồ họa.
* Mảng.
* Con trỏ.
* Chia để trị.
## 5. Kết luận:
### Hướng phát triển:
#### Về phần hình ảnh:
* Thêm những texture, ảnh nền, menu của trò chơi.
* Chỉnh Lại bố cục của trò chơi.
* Phát triển thêm mốt số họa ảnh khi xóa khổi hay đặt khối.
#### Về phần tính năng:
* Phát triển thêm phần tạm dừng trò chơi trong khi chơi.
#### Về phần âm thanh:
* Thêm một số âm thanh khi đặt khối, xóa khối.
### Điều tâm đắc rút ra sau khi hoàn thiện chương trình:
* Chương trình được tạo ra là sự kết hợp của âm thanh, hình ảnh, và chức nắng để người dùng có thế tiếp cận được dễ dàng hơn.
