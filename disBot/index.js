const Discord = require("discord.js");
const client = new Discord.Client();

let config = require("./botconfig.json");
let token = config.token;
let prefix = config.prefix;
let logchannel = config.logchannel;
//client.guilds.fetch('698226773174779934').then()
client.on("ready", () => {
  //console.log(client.guilds)
  console.log(`Bot ${client.user.username}`);

  client.user.setPresence({
    status: "online",
    activity: { type: "WATCHING", name: prefix + 'help' },
  });
});

client.on("message", (msg) => {
  if (msg.content === prefix + "help") {
    msg.channel.send("У меня нет команд");
    msg.guild.me.setNickname('bot');
  }

  if (msg.content === prefix + "ping")
    msg.channel.send(`pong!\`\`${Math.round(client.ws.ping)}ms\`\``)
});

client.on("messageUpdate", (omsg, nmsg) => {
  if (!omsg.author.bot) {
    const info = new Discord.MessageEmbed()
      .setColor("BLUE")
      .setAuthor(omsg.author.tag, omsg.author.avatarURL())
      .setDescription(`**${omsg.member} изменил сообщение в ${omsg.channel}** [Перейти к сообщению](https://discordapp.com/channels/${omsg.guild.id}/${omsg.channel.id}/${omsg.id})`)
      .addField("До", `${omsg.content}`)
      .addField("После", `${nmsg.content}`)
      .setFooter(`ID Пользователя: ${omsg.author.id}`)
      .setTimestamp()
    client.channels
      .fetch(logchannel)
      .then(channel => channel.send(info));
  }
})

client.on("messageDelete", (message) => {
  if (!message.author.bot) {
    const info = new Discord.MessageEmbed()
      .setColor('#f13d0b')
      .setAuthor(message.author.tag, message.author.avatarURL())
      .setDescription(
        `**Сообщение от ${message.member} удалено в ${message.channel}**\n${message.content}`
      ).setFooter(`Автор: ${message.author.id} | ID сообщения: ${message.id}`)
      .setTimestamp()
    client.channels
      .fetch(logchannel)
      .then((channel) => channel.send(info));
  }
  //console.log(message.author);
});

client.on("channelCreate", chan => {
  const info = new Discord.MessageEmbed()
    .setColor("GREEN")
    .setAuthor(chan.guild.name)
    .setDescription(`**Создан канал: #${chan.name}**`)
    .setFooter(`ID канала: ${chan.id}`)
    .setTimestamp()
  client.channels.fetch(logchannel).then(channel => channel.send(info));
})

client.on("channelDelete", chan => {
  const info = new Discord.MessageEmbed()
    .setColor("RED")
    .setAuthor(chan.guild.name)
    .setDescription(`**Удален канал: #${chan.name}**`)
    .setTimestamp()
  client.channels.fetch(logchannel).then(channel => channel.send(info));
})

client.on("guildMemberUpdate", (oldMem, newMem) => {
  oldMem.roles.cache.forEach(value => {
    if (newMem.roles.cache.find(role => role == value) == undefined) {
      const info = new Discord.MessageEmbed()
        .setColor("BLUE")
        .setAuthor(oldMem.user.tag, oldMem.user.avatarURL())
        .setDescription(`**${oldMem} убрана роль \`${value.name}\` **`)
        .setFooter(`ID: ${oldMem.id}`)
        .setTimestamp();
      client.channels.fetch(logchannel).then(channel => channel.send(info))
    }})
    newMem.roles.cache.forEach(value => {
      if (oldMem.roles.cache.find(role => role == value) == undefined) {
        const info = new Discord.MessageEmbed()
          .setColor("BLUE")
          .setAuthor(oldMem.user.tag, oldMem.user.avatarURL())
          .setDescription(`**${oldMem} выдана роль \`${value.name}\` **`)
          .setFooter(`ID: ${oldMem.id}`)
          .setTimestamp();
        client.channels.fetch(logchannel).then(channel => channel.send(info))
      }})
  if(oldMem.nickname != newMem.nickname){
    const info = new Discord.MessageEmbed()
      .setColor("YELLOW")
      .setAuthor(oldMem.user.tag, oldMem.user.avatarURL())
      .setDescription(`${oldMem} поменял никнейм`)
      .addField(`**До**`, `**\`${oldMem.nickname == null ? oldMem.user.username : oldMem.nickname}\`**`)
      .addField(`**После**`, `**\`${newMem.nickname == null ? newMem.user.username : newMem.nickname}\`**`)
      .setFooter(`'User ID: ${oldMem.id}`)
      .setTimestamp();
    client.channels.fetch(logchannel).then(channel => channel.send(info))
    }
})
client.login(token);



