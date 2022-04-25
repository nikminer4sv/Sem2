
from math import prod
import telebot
from telebot import apihelper
from telebot import types

apihelper.proxy = {'https': '63.161.104.189:3128'}
bot = telebot.TeleBot('5122481137:AAGvuvGAuir4a-9DazNSJFOiuco8SyNLogc')

product = types.KeyboardButton("Товар")
website = types.KeyboardButton("Отзывы")
donate = types.KeyboardButton("Оплатить")
qiwi = types.KeyboardButton("Qiwi")
card = types.KeyboardButton("Банковская карта")

cost = 0

@bot.message_handler(commands=['start'])
def start(message):
    markup = types.ReplyKeyboardMarkup(resize_keyboard=True, row_width=1, one_time_keyboard=True)

    start_text = f"Здравствуй, <b>{message.from_user.first_name}</b>\n"\
        + f"Нажми кнопку <b>{product.text}</b>"
        
    markup.add(product)
    bot.send_message(message.chat.id, start_text, parse_mode="html", reply_markup=markup)
    bot.register_next_step_handler(message, start_menu);

@bot.message_handler(content_types=['text'])
def start_menu(message):
    get_message_bot = message.text.strip().lower()

    print(message.text.lower() + "1")
    print(product.text.lower())
    if get_message_bot == product.text.lower():
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True, row_width=1, one_time_keyboard=True)

        global first_account
        first_account = types.KeyboardButton("55 AP, СЯО")
        global second_account
        second_account = types.KeyboardButton("12 AP, ЧЖУН ЛИ + ГАНЬ ЮЙ")

        markup.add(first_account, second_account)
        bot.send_message(message.chat.id, "Выберите аккаунт: ", reply_markup=markup)
        bot.register_next_step_handler(message, get_account)

@bot.message_handler(content_types=['text'])
def get_account(message):
    get_message_bot = message.text.strip().lower()
    if get_message_bot == second_account.text.lower():
        global cost
        cost = 500
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True, row_width=2, one_time_keyboard=True)
        global back
        back = types.KeyboardButton("ВЕРНУТЬСЯ")
        markup.add(donate, back)

        bot.send_message(message.chat.id, f"Стоимость = {cost}RUB", reply_markup=markup)

        bot.register_next_step_handler(message, check_buy)
        

    # elif get_message_bot == first_account.text.lower():
    #     cost = 750
    #     markup = types.ReplyKeyboardMarkup(resize_keyboard=True, row_width=2)
    #     global back
    #     back = types.KeyboardButton("ВЕРНУТЬСЯ")
    #     markup.add(donate, back)
    #     bot.send_message(message.chat.id, f"Стоимость = {cost}RUB", reply_markup=markup)

@bot.message_handler(content_types=['text'])
def check_buy(message):
    get_message_bot = message.text.strip().lower()

    if get_message_bot == back.text.lower():
        message.text = product.text
        print(message.text + "2")
        bot.register_next_step_handler(product, start_menu)
    else:
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True, row_width=1, one_time_keyboard=True)
        markup.add(qiwi, card)
        bot.send_message(message.chat.id, "Выберите способ оплаты: ", reply_markup=markup)
        bot.register_next_step_handler(message, get_buy)

@bot.message_handler(content_types=['text'])
def get_buy(message):
    get_message_bot = message.text.strip().lower()
    if get_message_bot == qiwi.text.lower():
        markup = types.InlineKeyboardMarkup()
        markup.add(types.InlineKeyboardButton("ОПЛАТИТЬ", url="https://google.com"))
        bot.send_message(message.chat.id, f"Произведи оплату в размере {cost} RUB", reply_markup=markup)


    elif get_message_bot == card.text.lower():
        markup = types.InlineKeyboardMarkup()
        markup.add(types.InlineKeyboardButton("ОПЛАТИТЬ", url="https://google.com"))
        bot.send_message(message.chat.id, f"Произведи оплату в размере {cost} RUB", reply_markup=markup)
     



bot.polling(none_stop=True)